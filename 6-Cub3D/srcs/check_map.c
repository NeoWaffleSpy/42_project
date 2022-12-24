/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:54:05 by ncaba             #+#    #+#             */
/*   Updated: 2021/05/04 20:38:49 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->map_size[0])
	{
		y = 0;
		while (y < map->map_size[1])
		{
			if (map->map[x][y] == 0)
			{
				if (x <= 0 || y <= 0 ||
					x >= map->map_size[0] - 1 || y >= map->map_size[1] - 1)
					call_error("Missing boundaries in the map 1", "");
				if (map->map[x + 1][y] < 0 || map->map[x][y + 1] < 0 ||
					map->map[x - 1][y] < 0 || map->map[x][y - 1] < 0)
					call_error("Missing boundaries in the map 2", "");
			}
			y++;
		}
		x++;
	}
}
