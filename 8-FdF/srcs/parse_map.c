/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:23:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/06 15:45:52 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	loop_size(t_map *map, int fd)
{
	int			buff;
	char		*line;
	char		*tmp;

	while (get_next_line(fd, &line))
	{
		tmp = line;
		if (ft_isdigit(*is_part_map(line)) || *is_part_map(line) == '-')
		{
			map->map_size[0]++;
			buff = 0;
			while (*is_part_map(line) != '\0' && *is_part_map(line) != '\n')
			{
				if (ft_isdigit(*is_part_map(line)) || *is_part_map(line) == '-')
					buff++;
				line = get_next_value(is_part_map(line));
			}
			if (map->map_size[1] == 0)
				map->map_size[1] = buff;
			else if (map->map_size[1] != buff)
				call_error("Map not consistent", tmp);
		}
		free(tmp);
	}
	free(line);
}

static void	get_size(t_map *map, char *filename)
{
	int			fd;

	if (filename[ft_strlen(filename)-1] == '/')
		call_error("Filename is a folder", filename);
	if (ft_strcmp(&filename[ft_strlen(filename)-4], ".fdf"))
		call_error("Filename extension is not .fdf", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		call_error("Filename invalid", filename);
	map->map_size[0] = 0;
	map->map_size[1] = 0;
	loop_size(map, fd);
	close(fd);
}

static int	*fill_map(t_map *map, char *line)
{
	int			*tab;
	int			loop;

	loop = 0;
	map->min_val = 0;
	map->max_val = 0;
	tab = (int *)calloc(sizeof(int), map->map_size[1] + 1);
	while (*line != '\0' && !ft_isspace(*line))
	{
		if (*line == '-' || ft_isdigit(*line))
			tab[loop] = (int)(ft_atoi(line));
		else
			call_error("Invalid character in map - 1:", line);
		loop++;
		line = is_part_map(get_next_value(line));
		if (tab[loop] > map->max_val)
			map->max_val = tab[loop];
		if (tab[loop] < map->min_val)
			map->min_val = tab[loop];
	}
	return (tab);
}

static void	set_map(t_map *map, char *filename)
{
	char		*line;
	int			fd;
	int			loop;

	loop = 0;
	fd = open(filename, O_RDONLY);
	map->map = (int **)calloc(sizeof(int *), map->map_size[0]);
	while (get_next_line(fd, &line))
	{
		if (!ft_isdigit(*is_part_map(line)) && *is_part_map(line) != '-')
		{
			free(line);
			call_error("Invalid character in map - 2:", line);
		}
		map->map[loop] = fill_map(map, line);
		loop++;
		free(line);
	}
	free(line);
	close(fd);
}

void	get_map(t_map *map, char *filename)
{
	int	loop;

	map->contraste = 2;
	get_size(map, filename);
	if (map->map_size[0] < 2 || map->map_size[1] < 1)
		call_error("No map in file:", filename);
	if (map->map_size[0] < 4 || map->map_size[1] < 4)
		call_error("Map size must be at least 4x4:", filename);
	map->zoom = 60 - (map->map_size[0] / 2);
	if (map->zoom < 2)
		map->zoom = 2;
	set_map(map, filename);
	map->grid = (t_coord **)calloc(sizeof(t_coord *), map->map_size[0]);
	loop = 0;
	while (loop < map->map_size[0])
	{
		map->grid[loop] = (t_coord *)calloc(sizeof(t_coord), map->map_size[1]);
		loop++;
	}
}
