/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:14:57 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/27 19:10:05 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	abs_val(double y)
{
	if (y < 0)
		return (y * -1);
	return (y);
}

void			get_col(t_tabint *s_pos, t_player *player)
{
	double	tmp_angle;
	int		loop;

	tmp_angle = s_pos->angle - player->angle + PI / 6;
	if (s_pos->angle - player->angle <= -PI)
		tmp_angle += 2 * PI;
	if (s_pos->angle - player->angle >= PI)
		tmp_angle -= 2 * PI;
	if (tmp_angle >= 0 && tmp_angle <= PI / 3)
	{
		s_pos->r_index = 0;
		loop = 1;
		while (loop < NB_RAYS)
		{
			if (abs_val(player->rays[loop].angle - s_pos->angle) <
				abs_val(player->rays[s_pos->r_index].angle - s_pos->angle))
				s_pos->r_index = loop;
			loop++;
		}
		return ;
	}
	s_pos->r_index = -1;
}

static void		real_draw2(t_draw d, t_data *data, t_map *map,
							t_tabint *s_pos)
{
	while (d.j < d.line)
	{
		d.pos_src[0] = d.i * map->sprite_entity.screen_size[0] / d.width;
		d.pos_src[1] = d.j * map->sprite_entity.screen_size[1] / d.line;
		d.pos_dst[0] = (s_pos->r_index * data->screen_size[0] / NB_RAYS) +
						d.i - (d.width / 2);
		d.pos_dst[1] = data->screen_size[1] / 2 - d.line / 2 + d.j;
		draw_cpy(&map->sprite_entity, d.pos_src, data, d.pos_dst);
		d.j++;
	}
}

void			real_draw(t_data *data, t_map *map,
							t_tabint *s_pos, t_player *p)
{
	t_draw	d;

	if (s_pos->r_index == -1)
		return ;
	d.line = (int)((30 * data->screen_size[1]) / s_pos->len) * 1.1;
	d.width = d.line;
	d.i = 0;
	while (d.i < d.width)
	{
		d.j = 0;
		d.index = ((s_pos->r_index * data->screen_size[0] / NB_RAYS) + d.i +
					1 - (d.width / 2)) * NB_RAYS / data->screen_size[0];
		if (d.index < 0)
			d.index = 0;
		if (d.index > NB_RAYS)
			d.index = NB_RAYS - 1;
		if (p->rays[d.index].length < s_pos->len)
		{
			d.i++;
			continue ;
		}
		real_draw2(d, data, map, s_pos);
		d.i++;
	}
}
