/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:44:47 by ncaba             #+#    #+#             */
/*   Updated: 2022/02/03 11:35:49 by ncaba            ###   ########.fr       */
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
/*
static void	draw_grid(t_map *map, t_graph *frame)
{
	int			i;
	int			j;
//	int			color_mult;

//	color_mult = 360 / (map->max_val - map->min_val);
	for(i = 0; i < map->map_size[0]; i++)
	{
		for(j = 0; j < map->map_size[1]; j++)
		{
			if(i < map->map_size[0] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
					map->grid[i + 1][j], map->map[i + 1][j]),
					&frame->img[0], 360);
			if(j < map->map_size[1] - 1)
				draw_line(
					get_line(map->grid[i][j], map->map[i][j],
					map->grid[i][j + 1], map->map[i][j + 1]),
					&frame->img[0], 360);
		}
	}
	for(int i = 0; i < map->map_size[0]; i++)
	{
		for(int j = 0; j < map->map_size[1]; j++)
		{
			ft_printf("%3d ", map->grid[i][j]);
		}
		ft_printf("\n");
	}
}*/

static void	do_render(t_vertices pos, t_map *map, t_veclist *data)
{
	t_vec4		vert;
	t_vertices	px;
	float		tmp_h;

	while (++pos.y < map->size[1])
	{
		pos.x = -1;
		while (map->heightmap[pos.y][++pos.x] != ((u_int16_t)-1))
		{
			tmp_h = ((map->heightmap[pos.y][pos.x] - map->median) / map->delta * -1) * data->zh;
			vert = vec4_newv(
				((float)pos.x - (map->size.x / 2.)) / map->size.y,
				((float)pos.y - (map->size.y / 2.)) / map->size.y, tmp_h, 1);
			vert = vec4_matmul(data->rot_mat, vert);
			px.color = get_rgb(data->rgb, tmp_h / data->zh);
			px.x = (int)((vert.flt.x * data->fov * data->zoom) + (data->win_width / 2.));
			px.y = (int)((vert.flt.z * data->fov * data->zoom) + (data->win_height / 2.));
			if (px.y >= data->win_height
			|| px.x >= data->win_width)
				px.x = ((u_int16_t)-2);
			data->zbuff[pos.y][pos.x] = px;
		}
		while (pos.x <= map->size.x)
			data->zbuff[pos.y][pos.x++].x = ((u_int16_t)-1);
	}
}

static void	build_rot_mat(t_data *d)
{
	float		cos[3];
	float		sin[3];

	cos[0] = cosf(d->rot.x);
	cos[1] = cosf(d->rot.y);
	cos[2] = cosf(d->rot.z);
	sin[0] = sinf(d->rot.x);
	sin[1] = sinf(d->rot.y);
	sin[2] = sinf(d->rot.z);
	d->rot_mat[0] = vec4_newv(
			cos[1] * cos[2], cos[2] * sin[0] * sin[1] - cos[0] * sin[2],
			cos[0] * cos[2] * sin[1] + sin[0] * sin[2], 0.f);
	d->rot_mat[1] = vec4_newv(cos[1] * sin[2],
			cos[0] * cos[2] + sin[0] * sin[1] * sin[2],
			cos[0] * sin[1] * sin[2] - cos[2] * sin[0], 0.f);
	d->rot_mat[2] = vec4_newv(-sin[1], cos[1] * sin[0], cos[0] * cos[1], 0.f);
	d->rot_mat[3] = vec4_newv(0.f, 0.f, 0.f, 1.f);
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
