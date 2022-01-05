/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:44:47 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 10:48:34 by ncaba            ###   ########.fr       */
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
	int			color_mult;

	color_mult = 360 / (map->max_val - map->min_val);
	for(i = 0; i < map->map_size[0]; i++)
	{
		for(j = 0; j < map->map_size[1]; j++)
		{
			if(i < map->map_size[0] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
					map->grid[i + 1][j], map->map[i + 1][j]),
					&frame->img[0], color_mult);
			if(j < map->map_size[1] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
					map->grid[i][j + 1], map->map[i][j + 1]),
					&frame->img[0], color_mult);
		}
	}
	/*
	for(int i = 0; i < map->map_size[0]; i++)
	{
		for(int j = 0; j < map->map_size[1]; j++)
		{
			ft_printf("%3d ", map->grid[i][j]);
		}
		ft_printf("\n");
	}
	*/
}

int			call_update(t_struct *data_struct)
{
	t_graph		*frame;

	frame = &data_struct->frame;
	ft_printf("passe 1\n");
	get_delta(&data_struct->timer);
	update_key(data_struct);
	ft_printf("passe 2\n");
	draw_grid(&data_struct->map, frame);
	ft_printf("passe 3\n");
	commit_img(frame, 0);
	return (0);
}
