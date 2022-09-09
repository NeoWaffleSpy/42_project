#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct	s_data
{
	int	old_fd;
	int	pipe;
}				t_data;

int		ft_strlen(char *str)
{
	if (!str)
		return 0;
	int i = -1;
	while (str[++i]);
	return i;
}

void	ft_putstr_err(char *str)
{
	if (!str)
		return;
	write(2, str, ft_strlen(str));
}

void fatal(int old_fd)
{
	ft_putstr_err("error: fatal\n");
	close(old_fd);
	exit(1);
}

void ft_cd(char **av)
{
	if (!av[1] || av[2])
		return (ft_putstr_err("error: cd: bad arguments\n"));
	if (chdir(av[1]) < 0)
	{
		ft_putstr_err("error: cannot change directory to ");
		ft_putstr_err(av[1]);
		ft_putstr_err("\n");
	}
}

void exec(t_data data, char **av, char **env)
{
	int	pid;
	int	fd[2];

	if (!strcmp(av[0], "cd"))
		return (ft_cd(av));
	if (data.pipe && pipe(fd) < 0)
		fatal(data.old_fd);
	if ((pid = fork()) < 0)
		fatal(data.old_fd);
	if (!pid)
	{
		if (data.pipe)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
		execve(av[0], av, env);
		ft_putstr_err("error: cannot execute ");
		ft_putstr_err(av[0]);
		ft_putstr_err("\n");
		close(data.old_fd);
		exit(1);
	}
	if (data.pipe)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
		dup2(data.old_fd, 1);
	waitpid(pid, 0, 0);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	int i = 1;
	int j = 1;
	t_data data;

	data.old_fd = dup(0);
	data.pipe = 0;
	while (av[i])
	{
		if (!strcmp(av[i], "|") || !strcmp(av[i], ";"))
		{
			if (!strcmp(av[i], "|"))
				data.pipe = 1;
			av[i] = NULL;
			exec(data, av + j, env);
			data.pipe = 0;
			j = i + 1;
		}
		else if (av[i + 1] == NULL)
			exec(data, av + j, env);
		i++;
	}
	close(data.old_fd);
}