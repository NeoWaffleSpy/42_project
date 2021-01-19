/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/19 17:00:55 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	call_destroy_frame(t_graph frame)
{
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
