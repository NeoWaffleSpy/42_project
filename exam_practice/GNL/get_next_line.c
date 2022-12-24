#include "get_next_line.h"
#include <stdio.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	get_new_line(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (-1);
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	str_dup(char *save)
{
	char	*replace;
	int	save_len;
	int	i;
	int	r;
	char	buff[10];

	i = -1;
	if ((r = read(0, buff, 9)) <= 0)
		return (-1);
	printf("pass\n");
	buff[r] = 0;
	if (save)
	{
		save_len = ft_strlen(save);
		replace = malloc(sizeof(int) * (save_len + ft_strlen(buff)) + 1);
		while (save[++i])
			replace[i] = save[i];
		while (buff[++i - save_len - 1])
			replace[i - 1] = buff[i - save_len - 1];
		replace[save_len + ft_strlen(buff)] = 0;
		free(save);
		save = replace;
	}
	else
	{
		replace = malloc(sizeof(int) * (ft_strlen(buff) + 1));
		while (++i < r)
			replace[i] = buff[i];
		replace[i] = 0;
		save = replace;
	}
	printf("Stored in Save: %s\n", save);
	return (1);
}

static char	*ft_strchr(char **save, int len)
{
	int	i;
	char	*new;
	char	*save_replace;

	i = 0;
	new = malloc(sizeof(char) * len + 1);
	save_replace = malloc(sizeof(char) * (ft_strlen(*save) - len) + 1);
	while (i < ft_strlen(*save))
	{
		if (i < len)
			new[i] = *save[i];
		else
			save_replace[i - len] = *save[i];
		free(*save);
		*save = save_replace;
	}
	new[len] = 0;
	return (new);
}

int	get_next_line(char	**line)
{
	static char	*save;
	int	len;

	while ((len = get_new_line(save)) == -1)
		if(str_dup(save) == -1)
			break;
	printf("Newline in: %s\n", save);
	if (*line)
		free(*line);
	if (len == -1)
	{
		if (ft_strlen(save) == 0)
			return (-1);
		*line = ft_strchr(&save, ft_strlen(save));
		printf("printing and clean: %s\n", save);
		free(save);
		return (0);
	}
	printf("printing: %s\n", save);
	*line = ft_strchr(&save, len);
	return (1);
}
