/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:36:24 by ncaba             #+#    #+#             */
/*   Updated: 2021/02/14 16:38:15 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

/*
static void		calc(double p[2], double d[2], int m[2], t_boolean isX)
{
	double	coeff;

	if (d[isX] >= 0)
		coeff = ((m[!isX] * BLOC_SIZE) - p[isX]) / (d[isX] - p[isX]);
	else
		coeff = ((m[!isX] * BLOC_SIZE) + p[isX]) / (d[isX] - p[isX]);
	if (coeff < 0)
		coeff *= -1;
	d[!isX] = coeff * (d[!isX] - p[!isX]) + p[!isX];
	if (d[isX] < 0)
		d[isX] = 0;
	else
		d[isX] = m[!isX];
}

static void		correc_values(t_calculs *c, t_map *map, t_player *p)
{
	if (c->m[0] < 0 || c->m[0] >= map->map_size[1])
		calc(p->pos, c->ray, map->map_size, 0);
	if (c->m[1] < 0 || c->m[1] >= map->map_size[0])
		calc(p->pos, c->ray, map->map_size, 1);
}
*/

static void		check_loop(t_calculs *c, t_map *map, t_player *player)
{
	(void)player;
	while (c->dist < c->max_dist)
	{
		c->m[0] = (int)(c->ray[0]) / BLOC_SIZE;
		c->m[1] = (int)(c->ray[1]) / BLOC_SIZE;
		if (c->m[0] < 0 || c->m[1] < 0 ||
			c->m[1] >= map->map_size[0] || c->m[0] >= map->map_size[1])
		{
/*			correc_values(c, map, player);
			c->dist = c->max_dist;
			c->has_touched = TRUE;
			*/
			c->ray[0] += c->delta[0];
			c->ray[1] += c->delta[1];
			c->dist++;
		}
		else if (map->map[c->m[1]][c->m[0]] == 1 ||
					map->map[c->m[1]][c->m[0]] < 0)
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

void			check_val(t_calculs *c, t_player *player, t_map *map, int t)
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
	check_loop(c, map, player);
}
