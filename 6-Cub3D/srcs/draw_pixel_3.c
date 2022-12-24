/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:02:56 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/27 17:45:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			draw_map(t_data *data, t_map *map)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < map->map_size[0])
	{
		j = 0;
		while (j < map->map_size[1])
		{
			color = 0x00222222;
			if (map->map[i][j] == 0)
				color = 0x00FFFFFF;
			if (map->map[i][j] == 1)
				color = 0x00222222;
			if (map->map[i][j] == 2)
				color = 0x0000AAAA;
			draw_square(data, get_rect_by_size(
							j * BLOC_MAP, i * BLOC_MAP, BLOC_MAP),
							color);
			j++;
		}
		i++;
	}
}

void			draw_rays(t_data *data, t_player *player)
{
	int	loop;

	loop = 0;
	while (loop++ < NB_RAYS)
	{
		draw_line(get_line(player->pos[0], player->pos[1],
						player->rays[loop].pos[0], player->rays[loop].pos[1]),
						data, 0x00FF0000);
	}
}
