/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:29:49 by ncaba             #+#    #+#             */
/*   Updated: 2022/02/03 10:28:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data*)param;
	keycode == K_UP ? data->rot.x += M_PI / data->mv : 0;
	keycode == K_DWN ? data->rot.x -= M_PI / data->mv : 0;
	keycode == K_LFT ? data->rot.z += M_PI / data->mv : 0;
	keycode == K_RGT ? data->rot.z -= M_PI / data->mv : 0;
	keycode == K_A ? data->rot.y += M_PI / data->mv : 0;
	keycode == K_D ? data->rot.y -= M_PI / data->mv : 0;
	keycode == K_W ? data->zoom *= 1.25 : 0;
	keycode == K_S ? data->zoom /= 1.25 : 0;
	keycode == K_Q ? data->zh /= 1.25 : 0;
	keycode == K_E ? data->zh *= 1.25 : 0;
	keycode == K_ESC ? exit(0) : 0;
	return (1);
}

void	init(t_data *dat, char *filename)
{
	int		i;

	dat->map.heightmap = NULL;
	read_map(&dat->map, filename);
	chaos((dat->mlx.ptr = mlx_init()));
	dat->win_height = 1024;
	dat->win_width = 1280;
	dat->zoom = dat->win_width / 2;
	dat->rgb = 0xFF0000;
	dat->zh = 1.;
	dat->mv = 8.;
	dat->rot.x = M_PI / dat->mv;
	dat->rot.y = 0;
	dat->rot.z = (M_PI * 2) / dat->mv;
	dat->fov = tan(1.22173047 / 2.);
	if (!(dat->zbuff = malloc((dat->map.size.y + 1) * sizeof(t_vertices*)))
		|| !(dat->zbuff[0] = malloc((dat->map.size.y + 1) *
		(dat->map.size.x + 1) * sizeof(t_vertices))))
		msg_exit("cannot allocate enough memory.", 0);
	i = -1;
	while (++i <= dat->map.size.y)
		dat->zbuff[i] = &dat->zbuff[0][i * (dat->map.size.x + 1)];
}

void	usage(void)
{
	msg_exit("Usage : ./fdf <filename> [-p] [-c] [-z] [-res]\n\
		\t-p precision: precision of rotation calculated as π/p, must be int\n\
		\t-c basecolor: color in capitalized hex w/o \"0x\" (default: FF0000)\n\
		\t-z zoom: dictate size of object, default to data->win_width / 2\n\
		\t-res width height: resolution of window, cannot be under 10", 0);
}

int		exec_render(t_data *d)
{
	render(&d->mlx, &d->map, d);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		msg_exit("niet. malloc failed", 0);
	if (argc == 1 || argv[1][0] == '-')
		usage();
	init(data, argv[1]);
	chaos((data->mlx.win = mlx_new_window(data->mlx.ptr,
		data->win_width, data->win_height, "Give good grade plz")));
	render(&data->mlx, &data->map, data);
	mlx_hook(data->mlx.win, 2, 1L, &keypress, data);
	mlx_loop_hook(data->mlx.ptr, &exec_render, data);
	mlx_hook(data->mlx.ptr, 17, 0, (void*)exit, 0);
	mlx_loop(data->mlx.ptr);
	return (0);
}
