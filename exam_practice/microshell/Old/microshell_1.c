#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int     ft_strlen(char *str);
void    ft_putstr_fd(char *str, int fd);
char    *ft_strdup(char *str);
int     ft_strcmp(char *str1, char *str2);
int     get_cmd(char ***cmd, int ac, char *av[]);
int     get_cmd_size(char **cmd);
void    clear_cmd(char ***cmd);
int     cd(char **cmd);
int     find_pipe(char **cmd);
void    exec_comm(char **cmd, char **envp);
int     exec_child(char** cmd, char** env, char** tmp, int fd_in, int fd_pipe[2]);

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr_fd(char *str, int fd)
{
    if (!str)
        return ;
    write(fd, str, ft_strlen(str));
}

void    print_error(char *str, char *opt)
{
    ft_putstr_fd("error: ", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd(opt, 2);
    ft_putstr_fd("\n", 2);
}

void    print_fatal(char **cmd)
{
    ft_putstr_fd("error: fatal\n", 2);
    clear_cmd(&cmd);
    exit(1);
}

char    *ft_strdup(char *str)
{
    char    *new;
    int     i;

    i = 0;
    new = malloc(sizeof(char) * ft_strlen(str) + 1);
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = 0;
    return (new);
}

int     ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    if (!str1 || !str2)
        return (-1);
    while (str1[i] && str2[i])
    {
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]);
        i++;
    }
    return (str1[i] - str2[i]);
}

int     get_cmd(char ***cmd, int ac, char *av[])
{
    int i;

    i = 0;
    while (i < ac)
    {
        if (!ft_strcmp(av[i], ";"))
            break;
        i++;
    }
    if (i == 0)
        return 1;
    *cmd = malloc(sizeof(char*) * (i + 1));
    i = 0;
    while (i < ac)
    {
        if (!ft_strcmp(av[i], ";"))
            break;
        (*cmd)[i] = ft_strdup(av[i]);
        i++;
    }
    (*cmd)[i] = 0;
    return (i + 1);
}

void    clear_cmd(char ***cmd)
{
    int i;

    i = 0;
    if (!*cmd)
        return ;
    while ((*cmd)[i])
    {
        free((*cmd)[i]);
        i++;
    }
    free(*cmd);
    *cmd = NULL;
}

int     get_cmd_size(char **cmd)
{
    int i;

    i = 0;
    while ((*cmd)[i])
        i++;
    return (i);
}

int    cd(char **cmd)
{
    if (get_cmd_size(cmd) != 2)
    {
        print_error("cd: bad arguments", "");
        return (1);
    }
    if (chdir(cmd[1]) < 0)
    {
        print_error("cd: cannot change directory to ", cmd[1]);
        return (1);
    }
    return (0);
}

int     find_pipe(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        if (!ft_strcmp(cmd[i], "|"))
            return (i);
        i++;
    }
    return -1;
}

void    exec_single(char **cmd, char **envp)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
        print_fatal(cmd);
    if (!pid)
    {
        if (execve(cmd[0], cmd, envp) < 0)
        {
            print_error("cannot execute ", cmd[0]);
        }
        clear_cmd(&cmd);
        exit(0);
    }
    waitpid(0, NULL, 0);
    return ;
}

int exec_child(char** cmd, char** envp, char** tmp, int fd_in, int fd_pipe[2])
{
    ft_putstr_fd("Pass 1\n", 2);
    if (dup2(fd_in, STDIN_FILENO) < 0)
        print_fatal(cmd);
    ft_putstr_fd("Pass 2\n", 2);
    if (dup2(fd_pipe[1], STDOUT_FILENO) < 0)
    {
        print_fatal(cmd);
    }
    ft_putstr_fd("Pass 3\n", 2);
	close(fd_in);
	close(fd_pipe[0]);
	close(fd_pipe[1]);

    ft_putstr_fd("Pass 4\n", 2);
    tmp[find_pipe(tmp)] = NULL;
    if (execve(cmd[0], cmd, envp) < 0)
    {
        print_error("cannot execute ", cmd[0]);
    }
    ft_putstr_fd("Pass 5\n", 2);
    clear_cmd(&cmd);
    exit(0);
}

void    exec_comm(char **cmd, char **envp)
{
    int nb_wait;

    nb_wait = 0;
    if (find_pipe(cmd) == -1)
        return (exec_single(cmd, envp));

    int fd_in;
    int fd_pipe[2];
    char **tmp;
    pid_t pid;

    tmp = cmd;
    fd_in = dup(STDIN_FILENO);
    if (fd_in < 0)
        print_fatal(cmd);
    
    while (tmp)
    {
        if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
            print_fatal(cmd);

        if (!pid)
            exec_child(cmd, envp, tmp, fd_in, fd_pipe);
        else
        {
            if (dup2(fd_pipe[0], fd_in) < 0)
                print_fatal(cmd);
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            nb_wait++;
            if (find_pipe(tmp) != -1)
                tmp += find_pipe(tmp) + 1;
            else
                tmp = NULL;
        }
    }
    close(fd_in);
    while (nb_wait > 0)
    {
		waitpid(0, NULL, 0);
        nb_wait--;
    }
}

int main(int ac, char *av[], char *envp[])
{
    char    **cmd;
    int     count;

    count = 1;
    while (1)
    {
        if (count >= ac)
            break;
        count += get_cmd(&cmd, ac - count, &av[count]);
        if (cmd)
        {
            if (!ft_strcmp(cmd[0], "cd"))
            {
                if (cd(cmd))
                    break ;
            }
            else
                exec_comm(cmd, envp);
            clear_cmd(&cmd);
        }
        clear_cmd(&cmd);
    }
    return 0;
}
