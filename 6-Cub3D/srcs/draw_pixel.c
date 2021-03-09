/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:39:00 by ncaba             #+#    #+#             */
/*   Updated: 2021/03/09 17:50:28 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->screen_size[0] || y > data->screen_size[1])
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_cpy(t_data *src, int *c1, t_data *dst, int *c2)
{
	char	*tmp;

	if (c2[0] < 0 || c2[1] < 0 ||
		c2[0] > dst->screen_size[0] || c2[1] > dst->screen_size[1])
		return ;
	if (c1[0] < 0 || c1[1] < 0 ||
		c1[0] > src->screen_size[0] || c1[1] > src->screen_size[1])
		return ;
	tmp = dst->addr + (c2[1] * dst->line_length + c2[0] *
						(dst->bits_per_pixel / 8));
	*(unsigned int*)tmp = *(unsigned int*)(src->addr + (c1[1] *
						src->line_length + c1[0] * (src->bits_per_pixel / 8)));
}

void	draw_clear_image(t_data *data)
{
	draw_square(data, get_rect_by_coord(
						0, 0, data->screen_size[0], data->screen_size[1]),
				0x00000000);
}

void	draw_map(t_data *data, t_map *map)
{
	int				i;
	int				j;
	unsigned int	color;

	i = 0;
	while (i < map->map_size[0])
	{
		j = 0;
		while (j < map->map_size[1])
		{
			color = 0x00222222;
			if (map->map[i][j] == 0)
				color = 0x00FFFFFF;
			if (map->map[i][j] == 1)
				color = 0x00222222;
			if (map->map[i][j] == 2)
				color = 0x0000AAAA;
			draw_square(data, get_rect_by_size(
							j * BLOC_MAP, i * BLOC_MAP, BLOC_MAP),
							color);
			j++;
		}
		i++;
	}
}

void	draw_rays(t_data *data, t_player *player)
{
	int	loop;

	loop = 0;
	while (loop++ < NB_RAYS)
	{
		draw_line(get_line(player->pos[0], player->pos[1], 
						player->rays[loop].pos[0], player->rays[loop].pos[1]),
						data, 0x00FF0000);
	}
}

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

void	draw_column(t_data *data, t_struct *data_struct, int index, t_rays ray)
{
	int	line;
	int	wall_pos[2];
	int	src[2];
	int	loop[2];

	loop[0] = index;
	loop[1] = 0;
	src[0] = (int)(ray.pos[1] * (data_struct->map.sprite_wall[ray.orientation].screen_size[0] / BLOC_SIZE)) % (BLOC_SIZE * (data_struct->map.sprite_wall[ray.orientation].screen_size[0] / BLOC_SIZE));
	if (ray.orientation <= 1)
		src[0] = (int)(ray.pos[0] * (data_struct->map.sprite_wall[ray.orientation].screen_size[0] / BLOC_SIZE)) % (BLOC_SIZE * (data_struct->map.sprite_wall[ray.orientation].screen_size[0] / BLOC_SIZE));
	if (ray.orientation % 2)
		src[0] = data_struct->map.sprite_wall[ray.orientation].screen_size[0] - src[0];
	if (ray.length <= 0)
	{
		while (loop[1]++ < data->screen_size[1])
			draw_pixel(data, loop[0], loop[1], 0x00FF0000);
		return;
	}
	line = (int)((30 * data->screen_size[1]) /
					correc_fisheye(&data_struct->player, ray));
	wall_pos[0] = data->screen_size[1] / 2 - line / 2;
	wall_pos[1] = data->screen_size[1] / 2 + line / 2;
	while (loop[1] < data->screen_size[1])
	{
		src[1] = (loop[1] - wall_pos[0]) *
		data_struct->map.sprite_wall[ray.orientation].screen_size[1] /
		(wall_pos[1] - wall_pos[0]);
		if (loop[1] < wall_pos[0])
			draw_pixel(data, loop[0], loop[1], 0x00555555);
		else if (loop[1] > wall_pos[1])
			draw_pixel(data, loop[0], loop[1], 0x00666666);
		else
			draw_cpy(&data_struct->map.sprite_wall[ray.orientation], src,
					data, loop);
		loop[1]++;
	}
}

static float	get_dist(double p1[2], double p2[2])
{
	return (sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) +
					(p1[1] - p2[1]) * (p1[1] - p2[1])));
}

static void	correct_coord(double corrected[2], double pos[2])
{
	corrected[0] = (double)((int)pos[0] / BLOC_SIZE * BLOC_SIZE);
	corrected[1] = (double)((int)pos[1] / BLOC_SIZE * BLOC_SIZE);
}

static void	calc_sprite(t_data *data, t_data *sprite, int index, t_player *p)
{
	double	corrected[2];
	int		true_line;
	int		line;
	int		wall_pos[2];
	int		loop;
	int		col;

	loop = 0;
	(void)sprite;
	correct_coord(corrected, p->rays[index].pos_s);
	true_line = (30 * data->screen_size[1]) /
					get_dist(p->pos, corrected);
	line = (int)(true_line * 0.75);
	wall_pos[0] = data->screen_size[1] / 2 - line / 4;
	wall_pos[1] = data->screen_size[1] / 2 + line * 0.75;
	while (loop < data->screen_size[1])
	{
		col = index * data->screen_size[0] / NB_RAYS;
		if (loop >= wall_pos[0] && loop <= wall_pos[1])
			while (col++ < ((index + 1) * data->screen_size[0] / NB_RAYS))
				draw_pixel(data, col, loop, 0x00009999);
		loop++;
	}
}

void		draw_sprites(t_data *data, t_data *sprite, t_player *player)
{
	int		loop;

	loop = 0;
	while (loop < NB_RAYS)
	{
		if (player->rays[loop].pos_s[0] != -1)
			calc_sprite(data, sprite, loop, player);
		loop++;
	}
}

void	commit_img(t_graph *frame, int img_nbr)
{
	mlx_put_image_to_window(frame->mlx_ptr,
							frame->win_ptr,
							frame->img[img_nbr].img_ptr,
							0, 0);
}
