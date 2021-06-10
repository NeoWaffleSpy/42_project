/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:23:05 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/10 13:23:34 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char			*is_part_map(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

static char			*get_next_value(char *line)
{
	while (*line != ' ' || *line != '\n' || *line != '\0')
		line++;
	return (line);
}

static void		get_size(t_map *map, char *filename)
{
	int			fd;
	int			buff;
	char		*line;

	fd = open(filename, O_RDONLY);
	map->map_size[0] = 0;
	map->map_size[1] = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_isdigit(*is_part_map(line)))
		{
			map->map_size[0]++;
			buff = 0;
			while (*is_part_map(line) != '\0' || *is_part_map(line) != '\n')
			{
				if (ft_isdigit(*is_part_map(line)))
					buff++;
				line = get_next_value(is_part_map(line));
			}
			if (map->map_size[1] == 0)
				map->map_size[1] = buff;
			else if (map->map_size[1] != buff)
				call_error("Map not consistent", filename);
		}
		free(line);
	}
	free(line);
	close(fd);
}

static int		*fill_map(t_map *map, char *line)
{
	int			*tab;
	int			loop;

	loop = 0;
	tab = (int*)calloc(sizeof(int), map->map_size[1] + 1);
	while (*line != '\0' || *line != '\n')
	{
		line = is_part_map(line);
		if (ft_isdigit(*line))
			tab[loop] = (int)(ft_atoi(line));
		else
			call_error("Invalid character in map:", line);
		loop++;
		line = get_next_value(line);
	}
	while (loop < map->map_size[1])
		tab[loop++] = -1;
	return (tab);
}

static void		set_map(t_map *map, char *filename)
{
	char		*line;
	int			fd;
	int			loop;

	loop = 0;
	fd = open(filename, O_RDONLY);
	map->map = (int**)calloc(sizeof(int*), map->map_size[0]);
	while (get_next_line(fd, &line))
	{
		if (!ft_isdigit(*is_part_map(line)))
		{
			free(line);
			continue ;
		}
		map->map[loop] = fill_map(map, line);
		loop++;
		free(line);
	}
	free(line);
	close(fd);
}

void			get_map(t_map *map, char *filename)
{
	get_size(map, filename);
	if (map->map_size[0] < 2 || map->map_size[1] < 1)
		call_error("No map in file:", filename);
	if (map->map_size[0] < 5 || map->map_size[1] < 5)
		call_error("Map size must be at least 5x5:", filename);
	set_map(map, filename);
}
