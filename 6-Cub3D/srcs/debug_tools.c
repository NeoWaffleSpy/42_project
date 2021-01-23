/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:41:48 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/23 18:43:59 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		debug_print_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->map_size[0])
	{
		y = 0;
		while (y < map->map_size[1])
		{
			if (x == map->player_pos[0] && y == map->player_pos[1])
				ft_printf("%s ", "\e[42m");
			else if (map->map[x][y] == -1)
				ft_printf("%s ", "\e[0m");
			else if (map->map[x][y] == 1)
				ft_printf("%s ", "\e[0;100m");
			else if (map->map[x][y] == 0)
				ft_printf("%s ", "\e[47m");
			else if (map->map[x][y] == 2)
				ft_printf("%s ", "\e[41m");
			y++;
		}
		x++;
		ft_printf("%s\n", "\e[0m");
	}
}
