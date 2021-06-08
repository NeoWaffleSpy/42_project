/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:25:41 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/08 17:33:51 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			main(int ac, char **av)
{
	t_struct	data_struct;

	if (ac != 2)
		call_error("Usage: %s <path_to_map>", av[0]);
	data_struct.timer.old_t = 0;
	data_struct.keys = init_keys();
	init_frame(av[1], &data_struct.frame, &data_struct.map);
	check_map(&data_struct.map);
	init_hooks(&data_struct);
	mlx_loop(data_struct.frame.mlx_ptr);
	call_destroy_frame(&data_struct);
	exit(0);
}

int			key_state(int keycode, t_struct *data_struct)
{
	t_keys	*keys;

	keys = &data_struct->keys;
	if (keycode == ESCAPE)
		mlx_loop_end((&data_struct->frame)->mlx_ptr);
	else if (keycode == keys->up.key_value)
		keys->up.is_pressed = !keys->up.is_pressed;
	else if (keycode == keys->down.key_value)
		keys->down.is_pressed = !keys->down.is_pressed;
	else if (keycode == keys->left.key_value)
		keys->left.is_pressed = !keys->left.is_pressed;
	else if (keycode == keys->right.key_value)
		keys->right.is_pressed = !keys->right.is_pressed;
	else if (keycode == keys->rot_right.key_value)
		keys->rot_right.is_pressed = !keys->rot_right.is_pressed;
	else if (keycode == keys->rot_left.key_value)
		keys->rot_left.is_pressed = !keys->rot_left.is_pressed;
	else if (keycode == keys->show_map.key_value)
		keys->show_map.is_pressed++;
	return (0);
}
