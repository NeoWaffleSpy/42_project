/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:10 by ncaba             #+#    #+#             */
/*   Updated: 2021/02/13 15:17:03 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

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

static void		move_player(t_player *player, double m[2], double angle, t_map *map)
{
	player->pos[1] += m[0];
	player->pos[0] += m[1];
	(void)angle;
	(void)map;
}
/*

static int		cast_ray(t_player *player, t_map *map, double angle, int type)
{
	t_calculs	calcul;

	calcul.max_dist = 1;
	calcul.ra = angle;
	if (type)
		calcul.n_tan = -1 / tan(calcul.ra);
	else
		calcul.n_tan = -tan(calcul.ra);
	check_val(&calcul, player, map, type);
	if (!calcul.has_touched)
		return (TRUE);
	return (FALSE);
}

static void		move_player(t_player *player, double m[2],
							double angle, t_map *map)
{
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (cast_ray(player, map, angle, 1))
		player->pos[1] += m[0];
	if (cast_ray(player, map, angle, 0))
		player->pos[0] += m[1];
}
*/
static double	*update_move(double m[2],double d1, double d2)
{
	m[0] = d1;
	m[1] = d2;
	return (m);
}
void			update_key(t_struct *data_struct)
{
	t_keys		*keys;
	t_player	*p;
	double		m[2];

	keys = &data_struct->keys;
	p = &data_struct->player;
	if (keys->up.is_pressed == TRUE)
		move_player(p, update_move(m, p->d_pos[1], p->d_pos[0]),
					p->angle, &data_struct->map);
	if (keys->down.is_pressed == TRUE)
		move_player(p, update_move(m, -p->d_pos[1], -p->d_pos[0]),
					p->angle + PI, &data_struct->map);
	if (keys->right.is_pressed == TRUE)
		move_player(p, update_move(m, p->d_pos[0], -p->d_pos[1]),
					p->angle + (3 * PI / 2), &data_struct->map);
	if (keys->left.is_pressed == TRUE)
		move_player(p, update_move(m, -p->d_pos[0], p->d_pos[1]),
					p->angle + (PI / 2), &data_struct->map);
	if (keys->rot_right.is_pressed == TRUE)
		reset_rot(p, ROTATE_SPEED);
	if (keys->rot_left.is_pressed == TRUE)
		reset_rot(p, -ROTATE_SPEED);
}
