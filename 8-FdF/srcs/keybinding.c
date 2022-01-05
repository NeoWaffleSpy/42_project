/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:10 by ncaba             #+#    #+#             */
/*   Updated: 2021/09/06 13:54:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void		reset_rot(t_player *player, double rot)
{
	player->angle += rot;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	player->d_pos[0] = cos(player->angle) * ROT_SPEED;
	player->d_pos[1] = sin(player->angle) * ROT_SPEED;
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
}*/

void			update_key(t_struct *d_s)
{
	t_keys		*keys;
	double		delta;
	double		m[2];

	keys = &d_s->keys;
	delta = d_s->timer.delta;
	(void)m;
	/*
	if (keys->up.is_pressed == TRUE)
	if (keys->down.is_pressed == TRUE)
	if (keys->right.is_pressed == TRUE)
	if (keys->left.is_pressed == TRUE)
	if (keys->rot_right.is_pressed == TRUE)
	if (keys->rot_left.is_pressed == TRUE)
	if (keys->show_map.is_pressed >= 4)
	*/
}
