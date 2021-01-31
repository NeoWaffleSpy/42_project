/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_top_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:17:20 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/31 19:47:20 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	t_struct	data_struct;

	if (ac != 2)
		call_error("Usage: %s <path_to_map>", av[0]);
	data_struct.keys = init_keys();
	init_frame(av[1], &data_struct.frame,
				&data_struct.map);
	init_player(&data_struct.player, &data_struct.map);
	init_hooks(&data_struct);
	mlx_loop(data_struct.frame.mlx_ptr);
	call_destroy_frame(&data_struct);
}

static void	update_key(t_struct *data_struct)
{
	t_keys		*keys;
	t_player	*player;

	keys = &data_struct->keys;
	player = &data_struct->player;
	if (keys->up.is_pressed == TRUE)
	{
		player->pos[1] += player->d_pos[1];
		player->pos[0] += player->d_pos[0];
	}
	if (keys->down.is_pressed == TRUE)
	{
		player->pos[1] -= player->d_pos[1];
		player->pos[0] -= player->d_pos[0];
	}
	if (keys->right.is_pressed == TRUE)
	{
		player->pos[1] += player->d_pos[0];
		player->pos[0] -= player->d_pos[1];
	}
	if (keys->left.is_pressed == TRUE)
	{
		player->pos[1] -= player->d_pos[0];
		player->pos[0] += player->d_pos[1];
	}
	if (keys->rot_right.is_pressed == TRUE)
	{
		player->angle += ROTATE_SPEED;
		if (player->angle > 2 * PI)
			player->angle -= 2 * PI;
		player->d_pos[0] = cos(player->angle) * PLAYER_SPEED;
		player->d_pos[1] = sin(player->angle) * PLAYER_SPEED;
	}
	if (keys->rot_left.is_pressed == TRUE)
	{
		player->angle -= ROTATE_SPEED;
		if (player->angle < 0)
			player->angle += 2 * PI;
		player->d_pos[0] = cos(player->angle) * PLAYER_SPEED;
		player->d_pos[1] = sin(player->angle) * PLAYER_SPEED;
	}
}

int			call_update(t_struct *data_struct)
{
	t_graph		*frame;
	t_player	*player;

	frame = &data_struct->frame;
	player = &data_struct->player;
	draw_clear_image(&frame->img[1]);
	update_key(data_struct);
	draw_map(&frame->img[1], &data_struct->map);
	ray_parse(player, &data_struct->map);
	draw_rays(&frame->img[1], player);
	draw_triangle(get_triangle(
						player->pos[0] + player->d_pos[0] * 6,
						player->pos[1] + player->d_pos[1] * 6,
						player->pos[0] + player->d_pos[1] * 2,
						player->pos[1] - player->d_pos[0] * 2,
						player->pos[0] - player->d_pos[1] * 2,
						player->pos[1] + player->d_pos[0] * 2),
						&frame->img[1], 0x0000AA00);
	commit_img(frame);
	return (0);
}

int			key_state(int keycode, t_struct *data_struct)
{
	t_keys	*keys;

	keys = &data_struct->keys;
	if (keycode == ESCAPE)
		mlx_loop_end((&data_struct->frame)->mlx_ptr);
	else if (keycode == keys->up.key_value)
		keys->up.is_pressed = !keys->up.is_pressed;
	else if (keycode == keys->down.key_value)
		keys->down.is_pressed = !keys->down.is_pressed;
	else if (keycode == keys->left.key_value)
		keys->left.is_pressed = !keys->left.is_pressed;
	else if (keycode == keys->right.key_value)
		keys->right.is_pressed = !keys->right.is_pressed;
	else if (keycode == keys->rot_right.key_value)
		keys->rot_right.is_pressed = !keys->rot_right.is_pressed;
	else if (keycode == keys->rot_left.key_value)
		keys->rot_left.is_pressed = !keys->rot_left.is_pressed;
	return (0);
}
