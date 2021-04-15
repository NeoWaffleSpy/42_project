/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:44:47 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/15 20:56:34 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_delta(t_timer *timer)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timer->new_t = ((double)time.tv_sec + ((double)time.tv_usec / 1000000));
	timer->delta = (timer->new_t - timer->old_t);
	timer->old_t = timer->new_t;
}

void		draw_2d_elem(t_graph *frame, t_player *player, t_map *map)
{
	int	posx;
	int	posy;

	posx = player->pos[0] * BLOC_MAP / BLOC_SIZE;
	posy = player->pos[1] * BLOC_MAP / BLOC_SIZE;
	draw_clear_image(&frame->img[1]);
	draw_map(&frame->img[1], map);
	draw_square(&frame->img[1],
		get_rect_by_size(posx - BLOC_MAP / 2, posy - BLOC_MAP / 2, BLOC_MAP),
		0x0000AA00);
}

void		draw_3d_elem(t_graph *frame, t_struct *data_struct)
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
	draw_sprites(&frame->img[0], &data_struct->map, &data_struct->player);
}

static void	cpy_map(t_graph *frame, t_map *map)
{
	int			x;
	int			y;
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
