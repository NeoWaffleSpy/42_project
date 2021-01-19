/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:49:02 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/19 22:11:09 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/include/ft_lib.h"
# include "minilibx-linux/mlx.h"
# define ESCAPE 65307

typedef struct	s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rot_right;
	int			rot_left;
}				t_keys;

typedef struct	s_data
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img[2];
	int			res_x;
	int			res_y;
}				t_graph;

typedef struct	s_map
{
	int			resolution[2];
	int			map_size[2];
	char		*color_floor;
	char		*color_roof;
	char		*sprite_entity;
	char		(*sprite_wall)[4];
	char		**map;
}				t_map;

t_keys			init_keys();
t_graph			init_frame();
t_map			parse(char *filename);
void			init_hooks(t_graph frame, t_keys keys);
void			draw_pixel(t_data *data, int x, int y, int color);
void			commit_img(t_graph frame);
void			call_destroy_frame(t_graph frame);
void			call_error(char *error, char *value);
void			call_info(char *info, char *value);
int				call_loop_end(int keycode, t_graph *frame);
int				call_update(t_graph *frame);

#endif
