/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 12:23:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/03/15 19:53:58 by ncaba            ###   ########.fr       */
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
	while (!ft_isspace(*line) && *line != '\0')
		line++;
	return (line);
}

static void		get_size(t_map *map, char *filename)
{
	int			fd;
	int			buff;
	char		*line;
	char		*tmp;

	if (filename[ft_strlen(filename)-1] == '/')
		call_error("Filename is a folder", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		call_error("Filename invalid", filename);
	map->map_size[0] = 0;
	map->map_size[1] = 0;
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
				call_error("Map not consistent", filename);
		}
		free(tmp);
	}
	free(line);
	close(fd);
}

static int		*fill_map(t_map *map, char *line)
{
	int			*tab;
	int			loop;

	loop = 0;
	map->min_val = 0;
	map->max_val = 0;
	tab = (int*)calloc(sizeof(int), map->map_size[1] + 1);
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

void			set_grid(t_map *map)
{
	int			startX;
	int			startY;
	int			loop;
	int			i;
	double		correc;

	correc = 0.6;
	map->grid = (t_coord**)calloc(sizeof(t_coord*), map->map_size[0]);
	for (loop = 0; loop < map->map_size[0]; loop++)
	{
		map->grid[loop] = (t_coord*)calloc(sizeof(t_coord), map->map_size[1]);
		startX = 1 + (map->map_size[0] - loop) * (int)map->zoom;
		startY = 6 + loop * ((int)map->zoom * correc);
		for(i = 0; i < map->map_size[1]; i++)
		{
			startX += (int)map->zoom;
			startY += ((int)map->zoom * correc);
			map->grid[loop][i].x = startX;
			map->grid[loop][i].y = startY - map->map[loop][i] *
									(int)(map->zoom / map->contraste);
		}
	}
}

void			get_map(t_map *map, char *filename)
{
	map->zoom = 10;
	map->contraste = 2;
	get_size(map, filename);
	if (map->map_size[0] < 2 || map->map_size[1] < 1)
		call_error("No map in file:", filename);
	if (map->map_size[0] < 5 || map->map_size[1] < 5)
		call_error("Map size must be at least 5x5:", filename);
	set_map(map, filename);
}
