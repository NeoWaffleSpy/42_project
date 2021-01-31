/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:49:02 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/31 20:02:55 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include "libft/include/ft_lib.h"
# include "minilibx-linux/mlx.h"
# define ESCAPE 65307
# define BLOC_SIZE 16
# define PLAYER_SPEED 2
# define ROTATE_SPEED 0.02
# define NB_RAYS 100

typedef int		t_color;

typedef struct	s_key
{
	int			key_value;
	t_boolean		is_pressed;
}				t_key;

typedef struct	s_keys
{
	t_key		up;
	t_key		down;
	t_key		left;
	t_key		right;
	t_key		rot_right;
	t_key		rot_left;
}				t_keys;

typedef struct	s_data
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screen_size[2];
}				t_data;

typedef struct	s_graph
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_data		img[2];
	int			res[2];
}				t_graph;

typedef struct	s_shapes
{
	int			pos_start[2];
	int			pos_end[2];
	int			pos_bonus[2];
}				t_shapes;

typedef struct	s_map
{
	int			map_size[2];
	t_color		color_floor;
	t_color		color_roof;
	void		*sprite_entity;
	void		*sprite_wall[4];
	int			**map;
	int			player_pos[2];
}				t_map;

typedef struct	s_rays
{
	double		angle;
	double		pos[2];
	double		length;
}				t_rays;

typedef struct	s_player
{
	double		pos[2];
	double		d_pos[2];
	double		angle;
	t_rays		rays[NB_RAYS];
}				t_player;

typedef struct	s_struct
{
	t_keys		keys;
	t_graph		frame;
	t_map		map;
	t_player	player;
}				t_struct;

t_keys			init_keys();
t_shapes		get_rect_by_size(int x0, int y0, int size);
t_shapes		get_rect_by_coord(int x0, int y0, int x1, int y1);
t_shapes		get_triangle(int x0, int y0, int x1, int y1, int x2, int y2);
t_shapes		get_line(int x0, int y0, int x1, int y1);
void			init_frame(char *data, t_graph *frame, t_map *map);
void			parse(char *filename, t_graph *frame, t_map *map);
char			*is_part_map(char *line);
void			get_map(t_map *map, char *filename);
void			init_hooks(t_struct *data_struct);
void			init_player(t_player *player, t_map *map);
void			draw_pixel(t_data *data, int x, int y, unsigned int color);
void			draw_square(t_data *data, t_shapes shape, unsigned int color);
void			draw_line(t_shapes shape, t_data *data, unsigned int color);
void			draw_triangle(t_shapes shape, t_data *data, unsigned int color);
void			draw_map(t_data *data, t_map *map);
void			draw_clear_image(t_data *data);
void			draw_rays(t_data *data, t_player *player);
void			ray_parse(t_player *player, t_map *map);
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
int				key_state(int keycode, t_struct *data_struct);

#endif
