/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:04:59 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/06 11:43:02 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_data	init_img(t_graph *frame)
{
	t_data	img;

	img.img_ptr = mlx_new_image(frame->mlx_ptr,
			frame->res[0], frame->res[1]);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	img.screen_size[0] = frame->res[0];
	img.screen_size[1] = frame->res[1];
	return (img);
}

static void	set_key(t_key *k, int value)
{
	k->key_value = value;
	k->is_pressed = FALSE;
}

t_keys	init_keys(void)
{
	t_keys	keys;

	set_key(&keys.arrow_r_key, 65363);
	set_key(&keys.arrow_l_key, 65361);
	set_key(&keys.arrow_u_key, 65362);
	set_key(&keys.arrow_d_key, 65364);
	set_key(&keys.plus_key, 65451);
	set_key(&keys.minus_key, 65453);
	set_key(&keys.z_key, 122);
	set_key(&keys.q_key, 113);
	set_key(&keys.s_key, 115);
	set_key(&keys.d_key, 100);
	return (keys);
}

void	init_frame(char *filename, t_graph *frame, t_map *map)
{
	int		sizex;
	int		sizey;

	frame->mlx_ptr = mlx_init();
	get_map(map, filename);
	frame->res[0] = map->map_size[1] * 20 + 200;
	frame->res[1] = map->map_size[0] * 10 + 200;
	mlx_get_screen_size(frame->mlx_ptr, &sizex, &sizey);
	if (frame->res[0] > sizex)
		frame->res[0] = sizex;
	if (frame->res[1] > sizey)
		frame->res[1] = sizey;
	frame->win_ptr = mlx_new_window(frame->mlx_ptr, frame->res[0],
			frame->res[1], "Fil de Fer");
	frame->img[0] = init_img(frame);
	frame->img[1] = init_img(frame);
}

void	init_hooks(t_struct *data_struct)
{
	t_graph	*frame;

	frame = &data_struct->frame;
	mlx_hook(frame->win_ptr, 33, 1L << 17, mlx_loop_end, frame->mlx_ptr);
	mlx_hook(frame->win_ptr, 2, 1L << 0, key_state, data_struct);
	mlx_hook(frame->win_ptr, 3, 1L << 1, key_state, data_struct);
	mlx_loop_hook(frame->mlx_ptr, &call_update, data_struct);
}
