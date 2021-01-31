/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 1c->max_dist:44:27 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/31 20:02:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

typedef struct	s_calculs
{
	int		dist;
	int		max_dist;
	int		m[2];
	double	ray[2];
	double	mem[2];
	double	delta[2];
	double	n_tan;
	double	ra;
	int		has_touched;
}				t_calculs;

static float	get_dist(double p1[2], double p2[2])
{
	return (sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) +
					(p1[1] - p2[1]) * (p1[1] - p2[1])));
}

static void		def_inc(t_calculs *c, t_player *player, int t)
{
	c->ray[t] = (((int)player->pos[t] / BLOC_SIZE) * BLOC_SIZE) - 0.0001;
	c->ray[!t] = (player->pos[t] - c->ray[t]) * c->n_tan + player->pos[!t];
	c->delta[t] = -BLOC_SIZE;
	c->delta[!t] = -c->delta[t] * c->n_tan;
}

static void		def_dec(t_calculs *c, t_player *player, int t)
{
	c->ray[t] = (((int)player->pos[t] / BLOC_SIZE) * BLOC_SIZE) + BLOC_SIZE;
	c->ray[!t] = (player->pos[t] - c->ray[t]) * c->n_tan + player->pos[!t];
	c->delta[t] = BLOC_SIZE;
	c->delta[!t] = -c->delta[t] * c->n_tan;
}

static void		check_loop(t_calculs *c, t_map *map)
{
	while (c->dist < c->max_dist)
	{
		c->m[0] = (int)(c->ray[0]) / BLOC_SIZE;
		c->m[1] = (int)(c->ray[1]) / BLOC_SIZE;
		if (c->m[0] >= 0 && c->m[1] >= 0 &&
			c->m[1] < map->map_size[0] && c->m[0] < map->map_size[1] &&
			map->map[c->m[1]][c->m[0]] == 1)
		{
			c->dist = c->max_dist;
			c->has_touched = TRUE;
		}
		else
		{
			c->ray[0] += c->delta[0];
			c->ray[1] += c->delta[1];
			c->dist++;
		}
	}
}

static void		check_val(t_calculs *c, t_player *player, t_map *map, int t)
{
	c->has_touched = FALSE;
	c->dist = 0;
	if ((t && c->ra > PI) ||
		(!t && c->ra > (PI / 2) && c->ra < ((3 * PI) / 2)))
		def_inc(c, player, t);
	else if ((t && c->ra < PI) ||
			(!t && (c->ra < (PI / 2) || c->ra > ((3 * PI) / 2))))
		def_dec(c, player, t);
	else
	{
		c->ray[0] = player->pos[0];
		c->ray[1] = player->pos[1];
		c->dist = c->max_dist;
	}
	check_loop(c, map);
}

static void		cpy_tab(double dst[2], double src[2])
{
	dst[0] = src[0];
	dst[1] = src[1];
}

static double	calc_angle(int r, double player_angle)
{
	double	angle;

	angle = player_angle - (PI / 6);
	angle += ((2 * PI / 6) / NB_RAYS) * r;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void			ray_parse(t_player *player, t_map *map)
{
	int			r;
	t_calculs	calcul;
	t_rays		ray;

	r = 0;
	calcul.max_dist = 20;
	calcul.mem[0] = -1;
	while (r++ < NB_RAYS)
	{
		player->rays[r].length = -1;
		calcul.ra = calc_angle(r, player->angle);
		calcul.n_tan = -1 / tan(calcul.ra);
		check_val(&calcul, player, map, 1);
		if (calcul.has_touched)
			cpy_tab(calcul.mem, calcul.ray);
		calcul.n_tan = -tan(calcul.ra);
		check_val(&calcul, player, map, 0);
		if (calcul.has_touched && calcul.mem[0] == -1)
			cpy_tab(ray.pos, calcul.ray);
		else if (!calcul.has_touched && calcul.mem[0] != -1)
			cpy_tab(ray.pos, calcul.mem);
		else if (calcul.has_touched && calcul.mem[0] != -1)
		{
			if (get_dist(player->pos, calcul.mem) <
				get_dist(player->pos, calcul.ray))
				cpy_tab(ray.pos, calcul.mem);
			else
				cpy_tab(ray.pos, calcul.ray);
		}
		else
			continue ;
		ray.length = get_dist(player->pos, ray.pos);
		player->rays[r] = ray;
	}
}

void	draw_rays(t_data *data, t_player *player)
{
	int	loop;

	loop = 0;
	while (loop++ < NB_RAYS)
	{
		if (player->rays[loop].length < 0 ||
			player->rays[loop].length > 10000)
			continue ;
		draw_line(get_line(player->pos[0], player->pos[1], 
						player->rays[loop].pos[0], player->rays[loop].pos[1]),
						data, 0x00FF0000);
	}
}
