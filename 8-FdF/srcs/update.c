/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:44:47 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/20 14:02:35 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_delta(t_timer *timer)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timer->new_t = ((double)time.tv_sec + ((double)time.tv_usec / 1000000));
	timer->delta = (timer->new_t - timer->old_t);
	timer->old_t = timer->new_t;
}

static void	draw_grid(t_map *map, t_graph *frame)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->map_size[0])
	{
		j = 0;
		while (j < map->map_size[1])
		{
			if (i < map->map_size[0] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
						map->grid[i + 1][j], map->map[i + 1][j]),
					&frame->img[0], 0x00AA2222);
			if (j < map->map_size[1] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
						map->grid[i][j + 1], map->map[i][j + 1]),
					&frame->img[0], 0x00AA2222);
			j++;
		}
		i++;
	}
}

int	call_update(t_struct *data_struct)
{
	t_graph		*frame;

	frame = &data_struct->frame;
	get_delta(&data_struct->timer);
	update_key(data_struct);
	draw_clear_image(&frame->img[0]);
	set_grid(&data_struct->map);
	draw_grid(&data_struct->map, frame);
	commit_img(frame, 0);
	return (0);
}
