/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 16:01:26 by ncaba             #+#    #+#             */
/*   Updated: 2021/03/28 19:42:05 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		get_sprites_count(t_map *map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (i < map->map_size[0])
	{
		j = 0;
		while (j < map->map_size[1])
		{
			if (map->map[i][j] == 2)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

static void		fill_sprites_pos(t_map *map, t_tabint *s_pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_size[0])
	{
		j = 0;
		while (j < map->map_size[1])
		{
			if (map->map[i][j] == 2)
			{
				s_pos->pos[1] = (double)(i * BLOC_SIZE) + BLOC_SIZE / 2;
				s_pos->pos[0] = (double)(j * BLOC_SIZE) + BLOC_SIZE / 2;
				s_pos++;
			}
			j++;
		}
		i++;
	}
}

static void	sort_sprites(t_player *player, t_tabint *s_pos, int iter, int max)
{
	double	tmp;

	if (max < 2 || iter < 0)
		return ;
	if (get_dist(player->pos, s_pos[iter].pos) <
			get_dist(player->pos, s_pos[iter + 1].pos))
	{
		tmp = s_pos[iter].pos[0];
		s_pos[iter].pos[0] = s_pos[iter + 1].pos[0];
		s_pos[iter + 1].pos[0] = tmp;
		tmp = s_pos[iter].pos[1];
		s_pos[iter].pos[1] = s_pos[iter + 1].pos[1];
		s_pos[iter + 1].pos[1] = tmp;
		sort_sprites(player, s_pos, max - 2, max);
		return ;
	}
	sort_sprites(player, s_pos, iter - 1, max);
}

static double	get_angle(double p_pos[], double s_pos[], double t_pos[])
{
	double	a;
	double	b;
	double	c;

	a = get_dist(p_pos, t_pos);
	b = get_dist(p_pos, s_pos);
	c = get_dist(s_pos, t_pos);
	if (s_pos[1] < p_pos[1])
		return (2 * PI - acos((a * a + b * b - c * c) / (2 * a * b)));
	return (acos((a * a + b * b - c * c) / (2 * a * b)));
}

static double	abs_val(double y)
{
	if(y < 0)
		return (y * -1);
	return (y);
}

static void		get_col(t_tabint *s_pos, t_player *player)
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
//		printf("true : %f - ", tmp_angle);
		s_pos->r_index = 0;
		loop = 1;
		while (loop < NB_RAYS)
		{
			if (abs_val(player->rays[loop].angle - s_pos->angle) <
				abs_val(player->rays[s_pos->r_index].angle - s_pos->angle))
				s_pos->r_index = loop;
			loop++;
		}
//		printf("rayon %d\n", s_pos->r_index);
		return ;
	}
	s_pos->r_index = -1;
//	printf("false\n");
}

static void	real_draw(t_data *data, t_map *map, t_tabint *s_pos, t_player *p)
{
	int	line;
	int	width;
	int	i;
	int	j;
	int	pos_src[2];
	int	pos_dst[2];

	if (s_pos->r_index == -1)
		return ;
	line = (int)((30 * data->screen_size[1]) / s_pos->len) * 1.1;
	width = line;
	i = 0;
	while (i < width)
	{
		j = 0;
		int	index;
		index = ((s_pos->r_index * data->screen_size[0] / NB_RAYS) + i + 1 - (width / 2)) * NB_RAYS / data->screen_size[0];
		if (index < 0)
			index = 0;
		if (index > NB_RAYS)
			index = NB_RAYS - 1;
		if (p->rays[index].length < s_pos->len)
		{
			i++;
			continue ;
		}
		while (j < line)
		{
			pos_src[0] = i * map->sprite_entity.screen_size[0] / width;
			pos_src[1] = j * map->sprite_entity.screen_size[1] / line;
			pos_dst[0] = (s_pos->r_index * data->screen_size[0] / NB_RAYS) +
							i - (width / 2);
			pos_dst[1] = data->screen_size[1] / 2 - line / 2 + j;
			draw_cpy(&map->sprite_entity, pos_src, data, pos_dst);
			j++;
		}
		i++;
	}
}

void		draw_sprites(t_data *data, t_map *map, t_player *player)
{
	t_tabint	*s_pos;
	int			nb_sprites;
	int			loop;
	double		pos_tmp[2];

	pos_tmp[0] = player->pos[0] + 10;
	pos_tmp[1] = player->pos[1];
	loop = 0;
	nb_sprites = get_sprites_count(map);
	if (!(s_pos = (t_tabint*)malloc(sizeof(t_tabint) * nb_sprites)))
		call_error("Malloc error", "s_pos in draw_sprites()");
	fill_sprites_pos(map, s_pos);
	sort_sprites(player, s_pos, nb_sprites - 2, nb_sprites);
//	printf("player_angle = %f\n", player->angle);
	while (loop < nb_sprites)
	{
		s_pos[loop].angle = get_angle(player->pos, s_pos[loop].pos, pos_tmp);
		s_pos[loop].len = get_dist(s_pos[loop].pos, player->pos);
//		printf("angle = %f : ", s_pos[loop].angle);
		get_col(&s_pos[loop], player);
		real_draw(data, map, &s_pos[loop], player);
		loop++;
	}
	free(s_pos);
}
