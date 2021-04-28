/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:10 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/28 16:33:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		reset_rot(t_player *player, double rot)
{
	player->angle += rot;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	player->d_pos[0] = cos(player->angle) * PLAYER_SPEED;
	player->d_pos[1] = sin(player->angle) * PLAYER_SPEED;
}

static void		move_player(t_player *player, double m[2], t_map *map)
{
	int pos_x;
	int pos_y;

	pos_x = (player->pos[1] + m[0] * C_BOX) / BLOC_SIZE;
	pos_y = (player->pos[0] + m[1] * C_BOX) / BLOC_SIZE;
	if (map->map[pos_x][(int)player->pos[0] / BLOC_SIZE] == 0)
		player->pos[1] += m[0];
	if (map->map[(int)player->pos[1] / BLOC_SIZE][pos_y] == 0)
		player->pos[0] += m[1];
}

static double	*up_m(double m[2], double d1, double d2, double delta)
{
	m[0] = d1 * delta;
	m[1] = d2 * delta;
	return (m);
}

void			update_key(t_struct *d_s)
{
	t_keys		*keys;
	t_player	*p;
	double		delta;
	double		m[2];

	keys = &d_s->keys;
	p = &d_s->player;
	delta = d_s->timer.delta;
	if (keys->up.is_pressed == TRUE)
		move_player(p, up_m(m, p->d_pos[1], p->d_pos[0], delta), &d_s->map);
	if (keys->down.is_pressed == TRUE)
		move_player(p, up_m(m, -p->d_pos[1], -p->d_pos[0], delta), &d_s->map);
	if (keys->right.is_pressed == TRUE)
		move_player(p, up_m(m, p->d_pos[0], -p->d_pos[1], delta), &d_s->map);
	if (keys->left.is_pressed == TRUE)
		move_player(p, up_m(m, -p->d_pos[0], p->d_pos[1], delta), &d_s->map);
	if (keys->rot_right.is_pressed == TRUE)
		reset_rot(p, ROTATE_SPEED * delta);
	if (keys->rot_left.is_pressed == TRUE)
		reset_rot(p, -ROTATE_SPEED * delta);
	if (keys->show_map.is_pressed >= 4)
		keys->show_map.is_pressed = 0;
}
