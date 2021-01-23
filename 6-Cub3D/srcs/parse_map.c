/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:19:56 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/23 18:48:56 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char			*is_part_map(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

static void		get_size(t_map *map, char *filename)
{
	int			fd;
	char		*line;
	t_boolean	has_map;

	has_map = FALSE;
	fd = open(filename, O_RDONLY);
	map->map_size[0] = 0;
	map->map_size[1] = 0;
	while (get_next_line(fd, &line))
	{
		if (!has_map && !ft_isdigit(*is_part_map(line)))
		{
			free(line);
			continue ;
		}
		has_map = TRUE;
		if (!ft_isdigit(*is_part_map(line)) && *is_part_map(line) != '\0')
			call_error("Map has invalid format:", line);
		if ((int)ft_strlen(line) > map->map_size[1])
			map->map_size[1] = (int)ft_strlen(line);
		map->map_size[0]++;
		free(line);
	}
	free(line);
	close(fd);
}

static int		*fill_map(t_map *map, char *line, int pos_y)
{
	int			*tab;
	int			loop;

	loop = 0;
	tab = (int*)calloc(sizeof(int), map->map_size[1] + 1);
	while(line[loop])
	{
		if (line[loop] == ' ')
			tab[loop] = -1;
		else if (ft_strchr("012", line[loop]))
			tab[loop] = (int)(line[loop] - '0');
		else if (ft_strchr("NSEW", line[loop]))
		{
			map->player_pos[1] = loop;
			map->player_pos[0] = pos_y;
			tab[loop] = 0;
		}
		else
			call_error("Invalid character in map:", line);
		loop++;
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
		map->map[loop] = fill_map(map, line, loop);
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
