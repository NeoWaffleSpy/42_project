/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:49:02 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/24 00:20:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/include/ft_lib.h"
# include "minilibx-linux/mlx.h"
# define ESCAPE 65307

typedef int		t_color;

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
	int			res[2];
}				t_graph;

typedef struct	s_map
{
	int			map_size[2];
	t_color		color_floor;
	t_color		color_roof;
	void		*sprite_entity;
	void		*sprite_wall[4];
	int			**map;
	double		player_pos[2];
}				t_map;

typedef struct	s_ray
{
	double		pos[2];
	double		dir[2];
	double		plane[2];
	double		time;
	double		old_time;
}				t_ray;

typedef struct	s_struct
{
	t_keys		keys;
	t_graph		frame;
	t_map		map;
	t_ray		ray;
}				t_struct;

t_keys			init_keys();
t_graph			init_frame(char *data, t_map *map);
t_map			parse(char *filename, t_graph *frame);
char			*is_part_map(char *line);
void			get_map(t_map *map, char *filename);
void			init_hooks(t_struct *data_struct);
void			init_ray(t_ray *ray, t_map *map);
void			draw_pixel(t_data *data, int x, int y, int color);
void			commit_img(t_graph *frame);
void			debug_print_map(t_map *map);
void			call_destroy_frame(t_struct *data_struct);
void			call_error(char *error, char *value);
void			call_info(char *info, char *value);
int				call_loop_end(int keycode, t_graph *frame);
int				call_update(t_struct *data_struct);
int				ft_strcmp_to_space(const char *s1, const char *s2);
t_color			create_color(int t, int r, int g, int b);
int				get_t(t_color color);
int				get_r(t_color color);
int				get_g(t_color color);
int				get_b(t_color color);

#endif
