/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:39:00 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/08 17:57:54 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void			draw_clear_image(t_data *data)
{
	draw_square(data, get_rect_by_coord(0, 0,
										data->screen_size[0],
										data->screen_size[1]),
				0x00000000);
}

void			commit_img(t_graph *frame, int img_nbr)
{
	mlx_put_image_to_window(frame->mlx_ptr,
							frame->win_ptr,
							frame->img[img_nbr].img_ptr,
							0, 0);
}
