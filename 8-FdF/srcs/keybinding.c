/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:10 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/06 11:43:18 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	set_zoom(double *zoom, double change)
{
	*zoom += change;
	if (*zoom < 1)
		*zoom = 1;
	else if (*zoom > 100)
		*zoom = 100;
}

static void	set_contraste(double *zoom, double change)
{
	*zoom += change;
	if (*zoom < 0.1)
		*zoom = 0.1;
	else if (*zoom > 100)
		*zoom = 100;
}

void	update_key(t_struct *d_s)
{
	t_keys		*keys;
	double		delta;

	keys = &d_s->keys;
	delta = d_s->timer.delta;
	if (keys->arrow_u_key.is_pressed == TRUE)
		set_zoom(&d_s->map.zoom, 10 * delta);
	if (keys->arrow_d_key.is_pressed == TRUE)
		set_zoom(&d_s->map.zoom, -10 * delta);
	if (keys->plus_key.is_pressed == TRUE)
		set_contraste(&d_s->map.contraste, -1 * delta);
	if (keys->minus_key.is_pressed == TRUE)
		set_contraste(&d_s->map.contraste, 1 * delta);
}

char	*is_part_map(char *line)
{
	while (*line && *line == ' ')
		line++;
	return (line);
}

void	set_grid(t_map *map)
{
	int			start_x;
	int			start_y;
	int			loop;
	int			i;

	map->grid = (t_coord **)calloc(sizeof(t_coord *), map->map_size[0]);
	loop = 0;
	while (loop < map->map_size[0])
	{
		map->grid[loop] = (t_coord *)calloc(sizeof(t_coord), map->map_size[1]);
		start_x = 1 + (map->map_size[0] - loop) * (int)map->zoom;
		start_y = 6 + loop * ((int)map->zoom * 0.6);
		i = 0;
		while (i < map->map_size[1])
		{
			start_x += (int)map->zoom;
			start_y += ((int)map->zoom * 0.6);
			map->grid[loop][i].x = start_x;
			map->grid[loop][i].y = start_y - map->map[loop][i]
				* (int)(map->zoom / map->contraste);
			i++;
		}
	loop++;
	}
}
