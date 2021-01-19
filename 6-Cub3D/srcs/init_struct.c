/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:04:59 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/18 13:57:05 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static t_data	init_img(t_graph frame)
{
	t_data	img;

	img.img_ptr = mlx_new_image(frame.mlx_ptr,
								frame.res_x,
								frame.res_y);
	img.addr = mlx_get_data_addr(img.img_ptr,
								&img.bits_per_pixel,
								&img.line_length,
								&img.endian);
	return (img);
}

t_keys			init_keys()
{
	t_keys keys;

	keys.up			= 122;
	keys.down		= 115;
	keys.left		= 113;
	keys.right		= 100;
	keys.rot_right	= 65363;
	keys.rot_left	= 65361;
	return (keys);
}

t_graph			init_frame()
{
	t_graph	frame;

	frame.res_x = 500;
	frame.res_y = 500;
	frame.mlx_ptr = mlx_init();
	frame.win_ptr = mlx_new_window(frame.mlx_ptr,
									frame.res_x,
									frame.res_y,
									"test");
	frame.img[0] = init_img(frame);
	frame.img[1] = init_img(frame);
	return (frame);
}

void			init_hooks(t_graph frame, t_keys keys)
{
	(void)keys;
	mlx_hook(frame.win_ptr, 33, 1L << 17, mlx_loop_end, frame.mlx_ptr);
	mlx_hook(frame.win_ptr, 2, 1L << 0, call_loop_end, &frame);
	mlx_loop_hook(frame.mlx_ptr, &call_update, &frame);
}
