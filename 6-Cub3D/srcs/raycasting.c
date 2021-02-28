/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:44:27 by ncaba             #+#    #+#             */
/*   Updated: 2021/02/28 16:25:30 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static float	get_dist(double p1[2], double p2[2])
{
	return (sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) +
					(p1[1] - p2[1]) * (p1[1] - p2[1])));
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

static int		fill_data(double pos[2], double ray[2], double angle, int or)
{
	ft_cpy_tab(pos, ray);
	if (!or)
	{
		if (angle < PI)
			return (1);
		else
			return (0);
	}
	else
	{
		if (angle >= PI / 2 && angle < 3 * PI / 2)
			return (3);
		else
			return (2);
	}
}

void			ray_parse(t_player *player, t_map *map)
{
	int			r;
	t_calculs	calcul;
	t_rays		ray;

	r = 0;
	calcul.max_dist = 40;
	calcul.mem[0] = -1;
	while (r++ < NB_RAYS)
	{
		calcul.mem[0] = -1;
		player->rays[r].length = -1;
		calcul.ra = calc_angle(r, player->angle);
		calcul.n_tan = -1 / tan(calcul.ra);
		check_val(&calcul, player, map, 1);
		if (calcul.has_touched)
			ft_cpy_tab(calcul.mem, calcul.ray);
		calcul.n_tan = -tan(calcul.ra);
		check_val(&calcul, player, map, 0);
		if (calcul.has_touched && calcul.mem[0] == -1)
			ray.orientation = fill_data(ray.pos, calcul.ray, calcul.ra, 1);
		else if (!calcul.has_touched && calcul.mem[0] != -1)
			ray.orientation = fill_data(ray.pos, calcul.mem, calcul.ra, 0);
		else if (calcul.has_touched && calcul.mem[0] != -1)
		{
			if (get_dist(player->pos, calcul.mem) <
				get_dist(player->pos, calcul.ray))
				ray.orientation = fill_data(ray.pos, calcul.mem, calcul.ra, 0);
			else
				ray.orientation = fill_data(ray.pos, calcul.ray, calcul.ra, 1);
		}
		else
			ray.orientation = fill_data(ray.pos, calcul.ray, calcul.ra, 1);
		ray.length = get_dist(player->pos, ray.pos);
		ray.angle = calcul.ra;
		player->rays[r] = ray;
	}
}
