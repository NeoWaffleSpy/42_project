/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:25:41 by ncaba             #+#    #+#             */
/*   Updated: 2022/03/15 13:36:05 by ncaba            ###   ########.fr       */
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
	else if (keycode == keys->arrowU_key.key_value)
		keys->arrowU_key.is_pressed = !keys->arrowU_key.is_pressed;
	else if (keycode == keys->arrowD_key.key_value)
		keys->arrowD_key.is_pressed = !keys->arrowD_key.is_pressed;
	else if (keycode == keys->plus_key.key_value)
		keys->plus_key.is_pressed = !keys->plus_key.is_pressed;
	else if (keycode == keys->minus_key.key_value)
		keys->minus_key.is_pressed = !keys->minus_key.is_pressed;
	else if (keycode == keys->z_key.key_value)
		keys->z_key.is_pressed = !keys->z_key.is_pressed;
	else if (keycode == keys->q_key.key_value)
		keys->q_key.is_pressed = !keys->q_key.is_pressed;
	else if (keycode == keys->s_key.key_value)
		keys->s_key.is_pressed = !keys->s_key.is_pressed;
	else if (keycode == keys->d_key.key_value)
		keys->d_key.is_pressed = !keys->d_key.is_pressed;
	return (0);
}
