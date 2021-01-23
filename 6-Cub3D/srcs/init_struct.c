/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:04:59 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/24 00:24:16 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_data	init_img(t_graph *frame)
{
	t_data	img;

	img.img_ptr = mlx_new_image(frame->mlx_ptr,
								frame->res[0],
								frame->res[1]);
	img.addr = mlx_get_data_addr(img.img_ptr,
								&img.bits_per_pixel,
								&img.line_length,
								&img.endian);
	return (img);
}

t_keys			init_keys(void)
{
	t_keys keys;

	keys.up = 122;
	keys.down = 115;
	keys.left = 113;
	keys.right = 100;
	keys.rot_right = 65363;
	keys.rot_left = 65361;
	return (keys);
}

t_graph			init_frame(char *data, t_map *map)
{
	t_graph	frame;

	frame.mlx_ptr = mlx_init();
	*map = parse(data, &frame);
	frame.win_ptr = mlx_new_window(frame.mlx_ptr,
									frame.res[0],
									frame.res[1],
									"test");
	frame.img[0] = init_img(&frame);
	frame.img[1] = init_img(&frame);
	return (frame);
}

void			init_hooks(t_struct *data_struct)
{
	t_graph	*frame;

	frame = &data_struct->frame;
	mlx_hook(frame->win_ptr, 33, 1L << 17, mlx_loop_end, frame->mlx_ptr);
	mlx_hook(frame->win_ptr, 2, 1L << 0, call_loop_end, frame);
	mlx_loop_hook(frame->mlx_ptr, &call_update, data_struct);
}

void			init_ray(t_ray *ray, t_map *map)
{
	ray->pos[0] = map->player_pos[0];
	ray->pos[1] = map->player_pos[1];
	ray->dir[0] = -1;
	ray->dir[0] = 0;
	ray->plane[0] = 0;
	ray->plane[0] = 0.66;
	ray->time = 0;
	ray->old_time = 0;
}
