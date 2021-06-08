/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:04:59 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/08 17:34:03 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_data	init_img(t_graph *frame)
{
	t_data	img;

	img.img_ptr = mlx_new_image(frame->mlx_ptr,
								frame->res[0],
								frame->res[1]);
	img.addr = mlx_get_data_addr(img.img_ptr,
								&img.bits_per_pixel,
								&img.line_length,
								&img.endian);
	img.screen_size[0] = frame->res[0];
	img.screen_size[1] = frame->res[1];
	return (img);
}

t_keys			init_keys(void)
{
	t_keys keys;

	keys.up.key_value = 122;
	keys.up.is_pressed = FALSE;
	keys.down.key_value = 115;
	keys.down.is_pressed = FALSE;
	keys.left.key_value = 113;
	keys.left.is_pressed = FALSE;
	keys.right.key_value = 100;
	keys.right.is_pressed = FALSE;
	keys.rot_right.key_value = 65363;
	keys.rot_right.is_pressed = FALSE;
	keys.rot_left.key_value = 65361;
	keys.rot_left.is_pressed = FALSE;
	keys.show_map.key_value = 109;
	keys.show_map.is_pressed = FALSE;
	return (keys);
}

void			init_frame(char *data, t_graph *frame, t_map *map)
{
	int		sizex;
	int		sizey;

	frame->mlx_ptr = mlx_init();
	parse(data, frame, map);
	mlx_get_screen_size(frame->mlx_ptr, &sizex, &sizey);
	if (frame->res[0] > sizex)
		frame->res[0] = sizex;
	if (frame->res[1] > sizey)
		frame->res[1] = sizey;
	frame->win_ptr = mlx_new_window(frame->mlx_ptr,
									frame->res[0],
									frame->res[1],
									"Cub3D");
	frame->img[0] = init_img(frame);
	frame->img[1] = init_img(frame);
}

void			init_hooks(t_struct *data_struct)
{
	t_graph	*frame;

	frame = &data_struct->frame;
	mlx_hook(frame->win_ptr, 33, 1L << 17, mlx_loop_end, frame->mlx_ptr);
	mlx_hook(frame->win_ptr, 2, 1L << 0, key_state, data_struct);
	mlx_hook(frame->win_ptr, 3, 1L << 1, key_state, data_struct);
	mlx_loop_hook(frame->mlx_ptr, &call_update, data_struct);
}
