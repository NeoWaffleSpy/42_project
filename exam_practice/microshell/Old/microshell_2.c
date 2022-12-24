#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int		ft_strlen(char *str);
void	ft_putstr_fd(int fd, char *str);
void	error(char *str1, char *str2);
void	fatal(char **cmd);
void	clear_cmd(char ***cmd);
int		find_pipe(char **cmd);
int		cmd_size(char **cmd);
char	*ft_strdup(char *str);
int		get_cmd(char ***cmd, int ac, char **av);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return -1;
	while (str[i])
		i++;
	return i;
}

char	*ft_strdup(char *str)
{
	int i;
	char *new;

	if (!str)
		return NULL;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return new;
}

void	ft_putstr_fd(int fd, char *str)
{
	if (!str)
		return;
	write(fd, str, ft_strlen(str));
}

void	error(char *str1, char *str2)
{
	ft_putstr_fd(2, "error: ");
	ft_putstr_fd(2, str1);
	ft_putstr_fd(2, str2);
	ft_putstr_fd(2, "\n");
}

void	fatal(char **cmd)
{
	error("fatal", "");
	clear_cmd(&cmd);
}

void	clear_cmd(char ***cmd)
{
	int i;

	i = 0;
	if (!*cmd)
		return;
	while ((*cmd)[i])
		free((*cmd)[i]);
	free(*cmd);
	*cmd = NULL;
}

int		cmd_size(char **cmd)
{
	int i;

	i = 0;
	if (!cmd)
		return -1;
	while (cmd[i++]);
	return i;
}

int		find_pipe(char **cmd)
{
	int i;

	i = 0;
	if (!cmd)
		return -1;
	while (cmd[i][0] != '|')
		i++;
	return i;
}

int		get_cmd(char ***cmd, int ac, char **av)
{
	int i;

	i = 0;
	if (ac <= 0)
		return -1;
	while (i < ac && av[i][0] != ';')
		(*cmd)[i] = ft_strdup(av[i]);
	(*cmd)[i] = NULL;
	return (i + 1);
}

int	main(int ac, char **av, char **envp)
{
	char **cmd;
	int	count;

	count = 1;
	while (1)
	{
		if (count >= ac)
			break;
		count += get_cmd(&cmd, ac - count, &av[count]);
		if (!cmd)
			break;

		clear_cmd(&cmd);
	}
	clear_cmd(&cmd);
}
