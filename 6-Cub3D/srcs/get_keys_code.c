/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:48:16 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/19 22:18:56 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int		random_fun(int key, t_keys *param)
{
	t_keys keys;

	keys = (*param);
	if (key == ESCAPE)
		return(0);
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
	t_graph	frame;
	t_keys	keys;

	if (ac != 2)
		call_error("Usage: %s <path_to_map>", av[0]);
	parse(av[1]);
	keys = init_keys();
	frame = init_frame();
	init_hooks(frame, keys);
	mlx_loop(frame.mlx_ptr);
	call_destroy_frame(frame);
	return (0);
}
