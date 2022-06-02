/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:23:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/02 15:53:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	loop_size(t_map *map, int fd, int *err)
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
				*err = map->map_size[0];
		}
		free(tmp);
	}
	free(line);
}

static void	get_size(t_map *map, char *filename, t_struct *data)
{
	int			fd;
	int			err;

	err = 0;
	if (filename[ft_strlen(filename)-1] == '/')
		call_destroy("Filename is a folder", filename, 1, data);
	if (ft_strcmp(&filename[ft_strlen(filename)-4], ".fdf"))
		call_destroy("Filename extension is not .fdf", filename, 1, data);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		call_destroy("Filename invalid", filename, 1, data);
	map->map_size[0] = 0;
	map->map_size[1] = 0;
	loop_size(map, fd, &err);
	if (err > 0)
		call_destroy("Map not consistent", "", 1, data);
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
			tab[loop] = 0;
		loop++;
		line = is_part_map(get_next_value(line));
		if (tab[loop] > map->max_val)
			map->max_val = tab[loop];
		if (tab[loop] < map->min_val)
			map->min_val = tab[loop];
	}
	return (tab);
}

static void	set_map(t_map *map, char *filename, t_struct *data)
{
	char		*line;
	int			fd;
	int			loop;
	int			err;

	loop = 0;
	err = 0;
	fd = open(filename, O_RDONLY);
	map->map = (int **)calloc(sizeof(int *), map->map_size[0]);
	while (get_next_line(fd, &line))
	{
		if (!ft_isdigit(*is_part_map(line)) && *is_part_map(line) != '-')
			err = loop;
		map->map[loop] = fill_map(map, line);
		loop++;
		free(line);
	}
	free(line);
	close(fd);
	if (err > 0)
		call_destroy("Invalid character in line:", ft_itoa(err), 2, data);
}

void	get_map(t_map *map, char *filename, t_struct *data)
{
	int	loop;

	map->contraste = 2;
	get_size(map, filename, data);
	if (map->map_size[0] < 2 || map->map_size[1] < 1)
		call_destroy("No map in file:", filename, 1, data);
	if (map->map_size[0] < 4 || map->map_size[1] < 4)
		call_destroy("Map size must be at least 4x4:", filename, 1, data);
	map->zoom = 60 - (map->map_size[0] / 2);
	if (map->zoom < 2)
		map->zoom = 2;
	set_map(map, filename, data);
	map->grid = (t_coord **)calloc(sizeof(t_coord *), map->map_size[0]);
	loop = 0;
	while (loop < map->map_size[0])
	{
		map->grid[loop] = (t_coord *)calloc(sizeof(t_coord), map->map_size[1]);
		loop++;
	}
}
