/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:43:35 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/06 13:26:02 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_square(t_data *data, t_shapes shape, unsigned int color)
{
	int			x;
	int			y;

	x = shape.pos_start[0];
	while (x < shape.pos_end[0])
	{
		y = shape.pos_start[1];
		while (y < shape.pos_end[1])
		{
			draw_pixel(data, x, y, color);
			y++;
		}
		x++;
	}
}

static void	add_value(int *err, int d, int *pos, int s)
{
	*err += d;
	*pos += s;
}

static void	init_val(t_shapes shape, int *d, int *s, int *err)
{
	d[0] = abs(shape.pos_end[0] - shape.pos_start[0]);
	if (shape.pos_start[0] < shape.pos_end[0])
		s[0] = 1;
	else
		s[0] = -1;
	d[1] = -abs(shape.pos_end[1] - shape.pos_start[1]);
	if (shape.pos_start[1] < shape.pos_end[1])
		s[1] = 1;
	else
		s[1] = -1;
	*err = d[0] + d[1];
}

void	draw_line(t_shapes shape, t_data *data, unsigned int color)
{
	int	d[2];
	int	s[2];
	int	err;
	int	e2;
	int	loop;

	loop = 0;
	init_val(shape, d, s, &err);
	while (loop++ < 2000)
	{
		draw_pixel(data, shape.pos_start[0], shape.pos_start[1], color);
		if (shape.pos_start[0] == shape.pos_end[0]
			&& shape.pos_start[1] == shape.pos_end[1])
			break ;
		e2 = 2 * err;
		if (e2 >= d[1])
			add_value(&err, d[1], &shape.pos_start[0], s[0]);
		if (e2 <= d[0])
			add_value(&err, d[0], &shape.pos_start[1], s[1]);
	}
}

t_shapes	get_rect_by_coord(int x0, int y0, int x1, int y1)
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
