/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:43:35 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/27 20:01:13 by ncaba            ###   ########.fr       */
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

void			draw_square(t_data *data, t_shapes shape, unsigned int color)
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

static void		add_value(int *err, int d, int *pos, int s)
{
	*err += d;
	*pos += s;
}

void			draw_line(t_shapes shape, t_data *data)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(shape.pos_end[0] - shape.pos_start[0]);
	sx = shape.pos_start[0] < shape.pos_end[0] ? 1 : -1;
	dy = -abs(shape.pos_end[1] - shape.pos_start[1]);
	sy = shape.pos_start[1] < shape.pos_end[1] ? 1 : -1;
	err = dx + dy;
	while (TRUE)
	{
		draw_pixel(data, shape.pos_start[0], shape.pos_start[1], 0x00FFFF00);
		if (shape.pos_start[0] == shape.pos_end[0] &&
			shape.pos_start[1] == shape.pos_end[1])
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
			add_value(&err, dy, &shape.pos_start[0], sx);
		if (e2 <= dx)
			add_value(&err, dx, &shape.pos_start[1], sy);
	}
}
/*
void			draw_line(t_shapes shape, t_data *data)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = shape.pos_start[0];
	x1 = shape.pos_end[0];
	y0 = shape.pos_start[1];
	y1 = shape.pos_end[1];
	dx = abs(x1-x0);
	sx = x0<x1 ? 1 : -1;
	dy = -abs(y1-y0);
	sy = y0<y1 ? 1 : -1;
	err = dx+dy;
	while (TRUE)
	{
		draw_pixel(data, x0, y0, 0x00FFFF00);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void			draw_line(t_shapes shape, t_data *data)
{
	int	sx;
	int	sy;
	int	err;
	int	e2;

	sx = shape.pos_start[0] < shape.pos_end[0] ? 1 : -1;
	sy = shape.pos_start[1] < shape.pos_end[1] ? 1 : -1;
	err = (abs(shape.pos_end[0] - shape.pos_start[0])) +
			(-abs(shape.pos_end[1] - shape.pos_start[1]));
	while (TRUE)
	{
		ft_printf("Coord: %3d - %3d\n", shape.pos_start[0], shape.pos_start[1]);
		draw_pixel(data, shape.pos_start[0], shape.pos_start[1], 0x00FFFF00);
		if (shape.pos_start[0] == shape.pos_end[0] &&
			shape.pos_start[1] == shape.pos_end[1])
			break;
		e2 = 2*err;
		if (e2 >= -abs(shape.pos_end[1] - shape.pos_start[1]))
		{
			err += -abs(shape.pos_end[1] - shape.pos_start[1]);
			shape.pos_start[0] += sx;
		}
		if (e2 <= abs(shape.pos_end[0] - shape.pos_start[0]))
		{
			err += abs(shape.pos_end[0] - shape.pos_start[0]);
			shape.pos_start[1] += sy;
		}
	}
}

void			draw_line(int x0, int y0, int x1, int y1, t_data *data)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1-x0);
	sx = x0<x1 ? 1 : -1;
	dy = -abs(y1-y0);
	sy = y0<y1 ? 1 : -1;
	err = dx+dy;
	while (TRUE)
	{
		draw_pixel(data, x0, y0, 0x00FFFF00);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2*err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}*/
