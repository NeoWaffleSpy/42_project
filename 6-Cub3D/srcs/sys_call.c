/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/23 16:22:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	call_destroy_frame(t_graph frame, t_map *map)
{
	int	loop;

	loop = 0;
	while (loop < map->map_size[0])
	{
		free(map->map[loop]);
		loop++;
	}
	free(map->map);
	mlx_destroy_image(frame.mlx_ptr, map->sprite_entity);
	mlx_destroy_image(frame.mlx_ptr, map->sprite_wall[0]);
	mlx_destroy_image(frame.mlx_ptr, map->sprite_wall[1]);
	mlx_destroy_image(frame.mlx_ptr, map->sprite_wall[2]);
	mlx_destroy_image(frame.mlx_ptr, map->sprite_wall[3]);
	mlx_destroy_image(frame.mlx_ptr, frame.img[0].img_ptr);
	mlx_destroy_image(frame.mlx_ptr, frame.img[1].img_ptr);
	mlx_destroy_window(frame.mlx_ptr, frame.win_ptr);
	mlx_destroy_display(frame.mlx_ptr);
	free(frame.mlx_ptr);
}

int		call_loop_end(int keycode, t_graph *frame)
{
	if (keycode == ESCAPE)
		mlx_loop_end(frame->mlx_ptr);
	return (0);
}

int		call_update(t_graph *frame)
{
	draw_pixel(&frame->img[1], 5, 5, 0x00FF0000);
	commit_img(*frame);
	return (0);
}

void	call_error(char *error, char *value)
{
	ft_printf("%s[%sError%s]: ", WHITE, RED, WHITE);
	ft_printf("%s %s%s%s\n", error, YELLOW, value, WHITE);
	exit(1);
}

void	call_info(char *info, char *value)
{
	ft_printf("%s[%sInfo%s]: ", WHITE, GREEN, WHITE);
	ft_printf("%-20s %s%s%s\n", info, CYAN, value, WHITE);
}
