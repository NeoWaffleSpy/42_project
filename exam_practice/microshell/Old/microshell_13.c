#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct	s_data
{
	int	old_stdin;
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

void	fatal(int old_stdin)
{
	ft_putstr_err("error: fatal\n");
	close(old_stdin);
	exit(1);
}

void	ft_cd(char **cmd)
{
	if (!cmd[1] || cmd[2])
		return (ft_putstr_err("error: cd: bad arguments\n"));
	if (chdir(cmd[1]) < 0)
	{
		ft_putstr_err("error: cannot change directory to ");
		ft_putstr_err(cmd[1]);
		ft_putstr_err("\n");
	}
}

void	exec(t_data data, char **cmd, char **env)
{
	if (!strcmp(cmd[0], "cd"))
		return (ft_cd(cmd));

	int	fd[2];
	int	pid;

	if (data.pipe && pipe(fd) < 0)
		fatal(data.old_stdin);
	if ((pid = fork()) < 0)
		fatal(data.old_stdin);
	if (!pid)
	{
		if (data.pipe)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
		execve(cmd[0], cmd, env);
		ft_putstr_err("error: cannot execute ");
		ft_putstr_err(cmd[0]);
		ft_putstr_err("\n");
		close(data.old_stdin);
		exit(1);
	}
	if (data.pipe)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
		dup2(data.old_stdin, 0);
	waitpid(pid, 0, 0);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	t_data data;
	int i = 1;
	int j = 1;

	data.old_stdin = dup(0);
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
		else if (!av[i + 1])
			exec(data, av + j, env);
		i++;
	}
	close(data.old_stdin);
}
