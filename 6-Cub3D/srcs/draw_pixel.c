/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:39:00 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/15 21:36:34 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			draw_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void			draw_cpy(t_data *src, int *c1, t_data *dst, int *c2)
{
	char	*tmp;

	if (c2[0] < 0 || c2[1] < 0 ||
		c2[0] > dst->screen_size[0] || c2[1] > dst->screen_size[1])
		return ;
	if (c1[0] < 0 || c1[1] < 0 ||
		c1[0] > src->screen_size[0] || c1[1] > src->screen_size[1])
		return ;
	if ((*(unsigned int*)(src->addr + (c1[1] * src->line_length + c1[0] *
	(src->bits_per_pixel / 8)))) == 0xFF000000)
		return ;
	tmp = dst->addr + (c2[1] * dst->line_length + c2[0] *
						(dst->bits_per_pixel / 8));
	*(unsigned int*)tmp = *(unsigned int*)(src->addr + (c1[1] *
						src->line_length + c1[0] * (src->bits_per_pixel / 8)));
}

void			draw_clear_image(t_data *data)
{
	draw_square(data, get_rect_by_coord(
						0, 0, data->screen_size[0], data->screen_size[1]),
				0x00000000);
}

void			commit_img(t_graph *frame, int img_nbr)
{
	mlx_put_image_to_window(frame->mlx_ptr,
							frame->win_ptr,
							frame->img[img_nbr].img_ptr,
							0, 0);
}
