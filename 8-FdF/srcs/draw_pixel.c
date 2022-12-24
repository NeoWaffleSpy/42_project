/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:39:00 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/20 14:00:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_clear_image(t_data *data)
{
	draw_square(data, get_rect_by_coord(0, 0,
			data->screen_size[0], data->screen_size[1]), 0x00000000);
}

void	commit_img(t_graph *frame, int img_nbr)
{
	mlx_put_image_to_window(frame->mlx_ptr,
		frame->win_ptr, frame->img[img_nbr].img_ptr, 0, 0);
}

t_shapes	get_line(t_coord p1, int h1, t_coord p2, int h2)
{
	t_shapes	shape;

	shape.pos_start[0] = p1.x;
	shape.pos_start[1] = p1.y;
	shape.h1 = h1;
	shape.pos_end[0] = p2.x;
	shape.pos_end[1] = p2.y;
	shape.h2 = h2;
	return (shape);
}
