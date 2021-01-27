/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_keys_code.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:48:16 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/24 19:22:08 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		random_fun(int key, t_keys *param)
{
	t_keys keys;

	keys = (*param);
	if (key == ESCAPE)
		return (0);
	else if (key == keys.up)
		ft_printf("You moved up\n");
	else if (key == keys.down)
		ft_printf("You moved down\n");
	else if (key == keys.left)
		ft_printf("You moved left\n");
	else if (key == keys.right)
		ft_printf("You moved right\n");
	else if (key == keys.rot_right)
		ft_printf("You rotated right\n");
	else if (key == keys.rot_left)
		ft_printf("You rotated left\n");
	else
		ft_printf("key = %d\n", key);
	return (0);
}

int		main(int ac, char **av)
{
	t_struct	data_struct;

	if (ac != 2)
		call_error("Usage: %s <path_to_map>", av[0]);
	data_struct.keys = init_keys();
	data_struct.frame = init_frame(av[1], &data_struct.map);
	init_ray(&data_struct.ray, &data_struct.map);
	init_hooks(&data_struct);
	debug_print_map(&data_struct.map);
	mlx_loop(data_struct.frame.mlx_ptr);
	call_destroy_frame(&data_struct);
	return (0);
}

int		call_update(t_struct *data_struct)
{
	t_graph	*frame;

	frame = &data_struct->frame;
	draw_pixel(&frame->img[1], 5, 5, 0x00FF0000);
	commit_img(frame);
	return (0);
}
