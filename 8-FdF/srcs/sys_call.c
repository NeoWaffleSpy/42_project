/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/02 15:58:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	call_destroy_frame(t_struct *data_struct)
{
	int		loop;
	t_graph	*frame;
	t_map	*map;

	frame = &data_struct->frame;
	map = &data_struct->map;
	loop = 0;
	while (loop < map->map_size[0])
	{
		free(map->map[loop]);
		free(map->grid[loop]);
		loop++;
	}
	free(map->map);
	free(map->grid);
	mlx_destroy_image(frame->mlx_ptr, frame->img[0].img_ptr);
	mlx_destroy_image(frame->mlx_ptr, frame->img[1].img_ptr);
	mlx_destroy_window(frame->mlx_ptr, frame->win_ptr);
	mlx_destroy_display(frame->mlx_ptr);
	free(frame->mlx_ptr);
}

int	call_loop_end(int keycode, t_graph *frame)
{
	if (keycode == ESCAPE)
		mlx_loop_end(frame->mlx_ptr);
	return (0);
}

void	call_error(char *error, char *value)
{
	ft_printf("%s[%sError%s]: ", WHITE, RED, WHITE);
	ft_printf("%s %s%s%s\n", error, YELLOW, value, WHITE);
	exit(1);
}

void	call_destroy(char *error, char *value, int free_bool, t_struct *data)
{
	int		loop;
	t_graph	*frame;
	t_map	*map;

	ft_printf("%s[%sError%s]: ", WHITE, RED, WHITE);
	ft_printf("%s %s%s%s\n", error, YELLOW, value, WHITE);
	if (free_bool > 1)
	{
		map = &data->map;
		loop = -1;
		while (++loop < map->map_size[0])
			free(map->map[loop]);
		free(map->map);
	}
	if (free_bool > 0)
	{
		frame = &data->frame;
		mlx_destroy_display(frame->mlx_ptr);
		free(frame->mlx_ptr);
	}
	else
		call_destroy_frame(data);
	exit(1);
}

void	call_info(char *info, char *value)
{
	ft_printf("%s[%sInfo%s]: ", WHITE, GREEN, WHITE);
	ft_printf("%-20s %s%s%s\n", info, CYAN, value, WHITE);
}
