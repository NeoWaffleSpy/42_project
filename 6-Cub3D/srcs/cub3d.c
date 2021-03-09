/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:17:20 by ncaba             #+#    #+#             */
/*   Updated: 2021/03/09 17:03:04 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int ac, char **av)
{
	t_struct	data_struct;

	if (ac != 2)
		call_error("Usage: %s <path_to_map>", av[0]);
	data_struct.timer.old_t = 0;
	data_struct.keys = init_keys();
	init_frame(av[1], &data_struct.frame,
				&data_struct.map);
	check_map(&data_struct.map);
	init_player(&data_struct.player, &data_struct.map);
	init_hooks(&data_struct);
	mlx_loop(data_struct.frame.mlx_ptr);
	call_destroy_frame(&data_struct);
	exit(0);
}

static void	draw_2d_elem(t_graph *frame, t_player *player, t_map *map)
{
	int	posx;
	int	posy;

	posx = player->pos[0] * BLOC_MAP / BLOC_SIZE;
	posy = player->pos[1] * BLOC_MAP / BLOC_SIZE;
	draw_clear_image(&frame->img[1]);
	draw_map(&frame->img[1], map);
	draw_triangle(get_triangle(
				posx + player->d_pos[0] * 0.06,
				posy + player->d_pos[1] * 0.04,
				posx + player->d_pos[1] * 0.04 - player->d_pos[0] * 0.06,
				posy - player->d_pos[0] * 0.04 - player->d_pos[1] * 0.06,
				posx - player->d_pos[1] * 0.04 - player->d_pos[0] * 0.06,
				posy + player->d_pos[0] * 0.04 - player->d_pos[1] * 0.06),
				&frame->img[1], 0x0000AA00);
}

static void	draw_3d_elem(t_graph *frame, t_struct *data_struct)
{
	double	loop;
	double	offset;
	double	ray_index;

	loop = 0;
	ray_index = 0;
	offset = (double)frame->res[0] / (double)NB_RAYS;
	while (loop < frame->res[0])
	{
		if (loop >= offset * (ray_index))
			ray_index++;
		draw_column(&frame->img[0], data_struct,
					(int)loop, data_struct->player.rays[(int)ray_index]);
		loop++;
	}
	draw_sprites(&frame->img[0], &data_struct->map.sprite_entity,
				&data_struct->player);
}

static void	cpy_map(t_graph *frame, t_map *map)
{
	int			x, y;
	t_shapes	coord;

	x = 0;
	while (x++ < map->map_size[1] * BLOC_MAP)
	{
		y = 0;
		while (y++ < map->map_size[0] * BLOC_MAP)
		{
			coord = get_line(x, y, x, y);
			draw_cpy(&frame->img[1], coord.pos_start,
					&frame->img[0], coord.pos_end);
		}
	}
}

static void	get_delta(t_timer *timer)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timer->new_t = ((double)time.tv_sec + ((double)time.tv_usec / 1000000));
	timer->delta = (timer->new_t - timer->old_t);
	timer->old_t = timer->new_t;
}

int			call_update(t_struct *data_struct)
{
	t_graph		*frame;
	t_player	*player;

	frame = &data_struct->frame;
	player = &data_struct->player;
	get_delta(&data_struct->timer);
	update_key(data_struct);
	ray_parse(player, &data_struct->map);
	draw_2d_elem(frame, player, &data_struct->map);
	draw_3d_elem(frame, data_struct);
	if (data_struct->keys.show_map.is_pressed)
		cpy_map(frame, &data_struct->map);
	commit_img(frame, 0);
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
	else if (keycode == keys->show_map.key_value)
		keys->show_map.is_pressed++;
	else
		ft_printf("new key: %d\n", keycode);
	return (0);
}
