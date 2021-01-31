/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:34:06 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/29 20:02:49 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		fill_top_triangle(t_shapes shape, t_data *data,
									unsigned int color)
{
	float	slope[2];
	float	cur[2];
	int		scanline;

	slope[0] = (float)(shape.pos_bonus[0] - shape.pos_start[0]) /
				(float)(shape.pos_bonus[1] - shape.pos_start[1]);
	slope[1] = (float)(shape.pos_end[0] - shape.pos_start[0]) /
				(float)(shape.pos_end[1] - shape.pos_start[1]);
	cur[0] = shape.pos_bonus[0];
	cur[1] = shape.pos_end[0];
	scanline = shape.pos_end[1];
	while (scanline <= shape.pos_start[1])
	{
		draw_line(get_line((int)cur[0], scanline, (int)cur[1], scanline),
					data, color);
		cur[0] += slope[0];
		cur[1] += slope[1];
		scanline++;
	}
}

static void		fill_bottom_triangle(t_shapes shape, t_data *data,
										unsigned int color)
{
	float	slope[2];
	float	cur[2];
	int		scanline;

	slope[0] = (float)(shape.pos_end[0] - shape.pos_start[0]) /
				(float)(shape.pos_end[1] - shape.pos_start[1]);
	slope[1] = (float)(shape.pos_end[0] - shape.pos_bonus[0]) /
				(float)(shape.pos_end[1] - shape.pos_bonus[1]);
	cur[0] = (float)shape.pos_start[0];
	cur[1] = (float)shape.pos_bonus[0];
	scanline = shape.pos_start[1];
	while (scanline > shape.pos_end[1])
	{
		draw_line(get_line((int)cur[0], scanline, (int)cur[1], scanline),
					data, color);
		cur[0] -= slope[0];
		cur[1] -= slope[1];
		scanline--;
	}
}

static void		sort_vertices(t_shapes *shape)
{
	if (shape->pos_bonus[1] > shape->pos_start[1])
	{
		ft_switch(&shape->pos_start[0], &shape->pos_bonus[0]);
		ft_switch(&shape->pos_start[1], &shape->pos_bonus[1]);
	}
	if (shape->pos_end[1] > shape->pos_bonus[1])
	{
		ft_switch(&shape->pos_bonus[0], &shape->pos_end[0]);
		ft_switch(&shape->pos_bonus[1], &shape->pos_end[1]);
	}
	if (shape->pos_bonus[1] > shape->pos_start[1])
	{
		ft_switch(&shape->pos_start[0], &shape->pos_bonus[0]);
		ft_switch(&shape->pos_start[1], &shape->pos_bonus[1]);
	}
}

static t_shapes	new_shapes(t_shapes shape, int cond)
{
	int			x;
	int			y;

	x = (int)(shape.pos_start[0] +
				((float)(shape.pos_bonus[1] - shape.pos_start[1]) /
				(float)(shape.pos_end[1] - shape.pos_start[1])) *
				(shape.pos_end[0] - shape.pos_start[0]));
	y = shape.pos_bonus[1];
	if (cond == 1)
		return (get_triangle(shape.pos_start[0], shape.pos_start[1],
					shape.pos_bonus[0], shape.pos_bonus[1],
					x, y));
	else
		return (get_triangle(shape.pos_bonus[0], shape.pos_bonus[1],
					x, y,
					shape.pos_end[0], shape.pos_end[1]));
}

void			draw_triangle(t_shapes shape, t_data *data, unsigned int color)
{
	sort_vertices(&shape);
	if (shape.pos_bonus[1] == shape.pos_end[1])
		fill_top_triangle(shape, data, color);
	else if (shape.pos_start[1] == shape.pos_bonus[1])
		fill_bottom_triangle(shape, data, color);
	else
	{
		fill_top_triangle(new_shapes(shape, 1), data, color);
		fill_bottom_triangle(new_shapes(shape, 2), data, color);
	}
}
