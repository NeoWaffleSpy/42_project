/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:10:09 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/27 17:43:52 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	correc_fisheye(t_player *p, t_rays ray)
{
	double	ca;

	ca = p->angle - ray.angle;
	if (ca < 0)
		ca += (2 * PI);
	else if (ca > (2 * PI))
		ca -= (2 * PI);
	return (ray.length * cos(ca));
}

static int		calc_src(double r_pos, int s_size)
{
	double	tmp;

	tmp = (r_pos * (s_size / BLOC_SIZE));
	return ((int)tmp % (BLOC_SIZE * (s_size / BLOC_SIZE)));
}

static void		draw_column_2(t_wall w, t_data *data, t_struct *data_struct)
{
	while (w.loop[1] < data->screen_size[1])
	{
		w.src[1] = (w.loop[1] - w.wall_pos[0]) * w.wall->screen_size[1] /
					(w.wall_pos[1] - w.wall_pos[0]);
		if (w.loop[1] < w.wall_pos[0])
			draw_pixel(data, w.loop[0], w.loop[1], data_struct->map.color_roof);
		else if (w.loop[1] > w.wall_pos[1])
			draw_pixel(data, w.loop[0], w.loop[1],
				data_struct->map.color_floor);
		else
			draw_cpy(w.wall, w.src, data, w.loop);
		w.loop[1]++;
	}
}

void			draw_column(t_data *data, t_struct *data_struct,
							int index, t_rays ray)
{
	t_wall	w;

	w.wall = &data_struct->map.sprite_wall[ray.orientation];
	w.loop[0] = index;
	w.loop[1] = 0;
	w.src[0] = calc_src(ray.pos[1], w.wall->screen_size[0]);
	if (ray.orientation <= 1)
		w.src[0] = calc_src(ray.pos[0], w.wall->screen_size[0]);
	if (ray.orientation % 2)
		w.src[0] = w.wall->screen_size[0] - w.src[0];
	if (ray.length <= 0)
	{
		while (w.loop[1]++ < data->screen_size[1])
			draw_pixel(data, w.loop[0], w.loop[1], 0x00FF0000);
		return ;
	}
	w.line = (int)((30 * data->screen_size[1]) /
				correc_fisheye(&data_struct->player, ray));
	w.wall_pos[0] = data->screen_size[1] / 2 - w.line / 2;
	w.wall_pos[1] = data->screen_size[1] / 2 + w.line / 2;
	draw_column_2(w, data, data_struct);
}
