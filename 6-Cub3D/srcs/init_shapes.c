/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:03:16 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/28 19:47:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_shapes		get_rect_by_size(int x0, int y0, int size)
{
	t_shapes	shape;

	shape.pos_start[0] = x0;
	shape.pos_start[1] = y0;
	shape.pos_end[0] = x0 + size;
	shape.pos_end[1] = y0 + size;
	return (shape);
}

t_shapes		get_rect_by_coord(int x0, int y0, int x1, int y1)
{
	t_shapes	shape;
	int			tmp;

	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
	}
	if (y0 > y1)
	{
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}
	shape.pos_start[0] = x0;
	shape.pos_start[1] = y0;
	shape.pos_end[0] = x1;
	shape.pos_end[1] = y1;
	return (shape);
}

t_shapes		get_line(int x0, int y0, int x1, int y1)
{
	t_shapes	shape;

	shape.pos_start[0] = x0;
	shape.pos_start[1] = y0;
	shape.pos_end[0] = x1;
	shape.pos_end[1] = y1;
	return (shape);
}

t_shapes		get_triangle(int x0, int y0, int x1, int y1, int x2, int y2)
{
	t_shapes	shape;

	shape.pos_start[0] = x0;
	shape.pos_start[1] = y0;
	shape.pos_bonus[0] = x1;
	shape.pos_bonus[1] = y1;
	shape.pos_end[0] = x2;
	shape.pos_end[1] = y2;
	return (shape);
}
