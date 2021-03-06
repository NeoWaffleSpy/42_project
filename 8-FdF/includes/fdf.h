/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:26:15 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/08 17:56:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <sys/time.h>
# include "libft/include/ft_lib.h"
# include "minilibx-linux/mlx.h"
# define ESCAPE 65307
# define ROT_SPEED 2

typedef int		t_color;

typedef struct	s_key
{
	int			key_value;
	t_boolean	is_pressed;
}				t_key;

typedef struct	s_keys
{
	t_key		up;
	t_key		down;
	t_key		left;
	t_key		right;
	t_key		rot_right;
	t_key		rot_left;
	t_key		show_map;
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
}				t_shapes;

typedef struct	s_map
{
	int			map_size[2];
	int			**map;
}				t_map;

typedef struct	s_timer
{
	double	old_t;
	double	new_t;
	double	delta;
}				t_timer;

typedef struct	s_struct
{
	t_keys		keys;
	t_graph		frame;
	t_map		map;
	t_timer		timer;
}				t_struct;

t_keys			init_keys();
t_shapes		get_line(int x0, int y0, int x1, int y1);
t_shapes		get_rect_by_coord(int x0, int y0, int x1, int y1);
float			get_dist(double p1[2], double p2[2]);
char			*is_part_map(char *line);
void			init_frame(char *data, t_graph *frame, t_map *map);
void			parse(char *filename, t_graph *frame, t_map *map);
void			get_map(t_map *map, char *filename);
void			init_hooks(t_struct *data_struct);
void			draw_pixel(t_data *data, int x, int y, unsigned int color);
void			draw_square(t_data *data, t_shapes shape, unsigned int color);
void			draw_line(t_shapes shape, t_data *data, unsigned int color);
void			draw_cpy(t_data *src, int *c1, t_data *dst, int *c2);
void			draw_clear_image(t_data *data);
void			commit_img(t_graph *frame, int img_nbr);
void			check_map(t_map *map);
void			update_key(t_struct *data_struct);
void			call_destroy_frame(t_struct *data_struct);
void			call_error(char *error, char *value);
void			call_info(char *info, char *value);
int				call_loop_end(int keycode, t_graph *frame);
int				call_update(t_struct *data_struct);
int				ft_strcmp_to_space(const char *s1, const char *s2);
int				get_t(t_color color);
int				get_r(t_color color);
int				get_g(t_color color);
int				get_b(t_color color);
int				key_state(int keycode, t_struct *data_struct);
unsigned int	get_pixel(t_data *data, int x, int y);
t_color			create_color(int t, int r, int g, int b);

#endif
