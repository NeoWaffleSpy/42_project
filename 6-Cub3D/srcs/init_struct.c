/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:04:59 by ncaba             #+#    #+#             */
/*   Updated: 2021/02/28 16:36:45 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	frame->mlx_ptr = mlx_init();
	parse(data, frame, map);
	frame->win_ptr = mlx_new_window(frame->mlx_ptr,
									frame->res[0],
									frame->res[1],
									"test");
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

void			init_player(t_player *player, t_map *map)
{
	player->pos[0] = map->player_pos[0] * BLOC_SIZE + BLOC_SIZE / 2;
	player->pos[1] = map->player_pos[1] * BLOC_SIZE + BLOC_SIZE / 2;
	player->angle = 0;
	player->d_pos[0] = cos(player->angle) * PLAYER_SPEED;
	player->d_pos[1] = sin(player->angle) * PLAYER_SPEED;
}
