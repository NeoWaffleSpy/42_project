/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:39:00 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/27 16:08:45 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_clear_image(t_data *data)
{
	draw_square(data, get_rect_by_coord(
						0, 0, data->screen_size[0], data->screen_size[1]),
				0x00000000);
}

void	draw_map(t_data *data, t_map *map)
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
			color = 0x00000000;
			if (map->map[i][j] == 0)
				color = 0x00FFFFFF;
			if (map->map[i][j] == 1)
				color = 0x00555555;
			if (map->map[i][j] == 2)
				color = 0x00FF0000;
			draw_square(data, get_rect_by_size(
							j * BLOC_SIZE, i * BLOC_SIZE, BLOC_SIZE - 1),
							color);
			j++;
		}
		i++;
	}
}

void	commit_img(t_graph *frame)
{
	mlx_put_image_to_window(frame->mlx_ptr,
							frame->win_ptr,
							frame->img[1].img_ptr,
							0, 0);
}
/*
void draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	int	m_new;
	int	slope_new;
	int	x;
	int	y;

	m_new = 2 * (y1 - y0);
	slope_new = m_new - (x1 - x0);
	x = x0;
	y = y0;
	while (x < x1)
	{
		draw_pixel(data, x, y, 0x00FFFF00);
		slope_new += m_new;
		if (slope_new >= 0)
		{
			y++;
			slope_new -= (2 * (x1 - x0));
		}
		x++;
	}
} */
