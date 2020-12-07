/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:25:18 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/05 20:02:59 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void		ft_exit(const char *str)
{
	if (str)
		printf("%s\n", str);
	exit(1);
}

/* Main pour STDIN 

int			main(void)
{
	char	*line;
	int		fd;
	int		code;
	int		len;

	fd = 0;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("___FD___ \n\n");
	while ((code = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		printf("%d - %d - |%s|\n", code, len, line);
		free(line);
	}
	return (0);
}*/

/* Main basique */

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		code;
	int		len;
	int		i;

	i = 1;
	printf("BUFF_SIZE = %d\n", BUFFER_SIZE);
	printf("___Premier FD___ \n\n");
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_exit("Error: Can't open file");
		do
		{
			code = get_next_line(fd, &line);
			len = ft_strlen(line);
			printf("%d - %4d - |%s|\n", code, len, line);
			free(line);
		} while (code > 0);
		i++;
		if (i < argc)
			printf("\n___Changement de FD___ \n\n");
	}
	return (code);
}
