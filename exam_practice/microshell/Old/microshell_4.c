#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int ft_strlen(char *str)
{
    int i = -1;

    if (!str)
        return 0;
    while (str[++i]);
    return i;
}

int ft_putstr_err(char *str)
{
    write(STDERR_FILENO, str, ft_strlen(str));
    return 0;
}

int fatal(char **free_ptr)
{
    ft_putstr_err("error: fatal\n");
    free(free_ptr);
    exit(1);
}

int get_cmd_size(char **cmd, char *pattern)
{
    int i = -1;

    if (!cmd)
        return 0;
    while (cmd[++i])
        if (pattern && !strcmp(cmd[i], pattern))
            return i;
    return i;
}

char **find_next_pipe(char **cmd)
{
	if (!cmd)
		return (0);
	int i = -1;
	while(cmd[++i])
		if (!strcmp(cmd[i], "|"))
			return (&cmd[i + 1]);
	return NULL;
}

char **add_cmd(char **av, int *i)
{
    char **tmp = NULL;
    int size = get_cmd_size(&av[*i], ";");
    if (!size)
        return (NULL);
    if (!(tmp = malloc(sizeof(*tmp) * (size + 1))))
        fatal(NULL);

    int j = -1;
    while (++j < size)
        tmp[j] = av[j + *i];
    tmp[j] = NULL;
    *i += size;
    return (tmp);
}

int builtin_cd(char **cmd)
{
    if (get_cmd_size(cmd, NULL) != 2)
        return (ft_putstr_err("error: cd: bad arguments\n"));
    if (chdir(cmd[1]) < 0)
    {
        ft_putstr_err("error: cd: cannot change directory to ");
        ft_putstr_err(cmd[1]);
        ft_putstr_err("\n");
    }
    return 0;
}

int exec_comm(char **cmd, char **env, char **free_ptr)
{
    pid_t pid;

    if ((pid = fork()) < 0)
        fatal(free_ptr);
    if (!pid)
    {
        if (execve(cmd[0], cmd, env) < 0)
        {
            ft_putstr_err("error: cannot execute ");
            ft_putstr_err(cmd[0]);
            ft_putstr_err("\n");
            free(free_ptr);
        }
    }
    waitpid(0, NULL, 0);
    return (0);
}

int exec_son(char **free_ptr, char **env, char **cmd, int fd_in, int fd_pipe[2])
{
    if (dup2(fd_in, STDIN_FILENO) < 0)
        fatal(cmd);
    if (find_next_pipe(cmd) && dup2(fd_pipe[1], STDOUT_FILENO) < 0)
        fatal(cmd);
    
    close(fd_in);
    close(fd_pipe[0]);
    close(fd_pipe[1]);

    cmd[get_cmd_size(cmd, "|")] = NULL;
    exec_comm(cmd, env, free_ptr);
    free(free_ptr);
    exit(0);
}

int execute(char **cmd, char **env)
{
    if (!find_next_pipe(cmd))
        return (exec_comm(cmd, env, cmd));

    int fd_in;
    int fd_pipe[2];
    char **tmp = cmd;
    int nb_wait = 0;
    pid_t pid;

    if ((fd_in = dup(STDIN_FILENO)) < 0)
        return (fatal(cmd));
    while (tmp)
    {
        if (pipe(fd_pipe) < 0 || (pid = fork()) < 0)
            fatal(cmd);
        if (!pid)
            exec_son(cmd, env, tmp, fd_in, fd_pipe);
        else
        {
            if (dup2(fd_pipe[0], fd_in) < 0)
                fatal(cmd);
            close(fd_pipe[0]);
            close(fd_pipe[1]);
            ++nb_wait;
            tmp = find_next_pipe(tmp);
        }
    }
    close(fd_in);
    while (--nb_wait >= 0)
        waitpid(0, NULL, 0);
    return 0;
}

int main(int ac, char **av, char **env)
{
    char **cmd = NULL;
    int i = 0;
    while (++i < ac)
    {
        cmd = add_cmd(av, &i);
        if (cmd && !strcmp(cmd[0], "cd"))
            builtin_cd(cmd);
        else if(cmd)
            execute(cmd, env);
        if (cmd)
            free(cmd);
        cmd = NULL;
    }
    return 0;
}