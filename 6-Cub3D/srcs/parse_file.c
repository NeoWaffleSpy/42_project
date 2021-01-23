/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:09:55 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/23 17:22:56 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		*get_sprite(char *data, t_graph *frame)
{
	void	*img;
	int		x;
	int		y;

	while (*data && *data != ' ')
		data++;
	data++;
	if (ft_strnstr(data, ".xpm", ft_strlen(data)))
	{
		img = mlx_xpm_file_to_image(frame->mlx_ptr, data, &x, &y);
		if (img == NULL)
			call_error("Invalid file:", data);
		return (img);
	}
	call_error("Invalid file format:", data);
	return (NULL);
}

static void		fill_res(t_graph *frame, char *data)
{
	int		loop;
	char	*tmp;

	loop = 0;
	tmp = data;
	while (*data)
	{
		if (loop > 1)
			call_error("Invalid format:", tmp);
		while (*data && *data != ' ')
			data++;
		data++;
		if (ft_isdigit(*data))
			frame->res[loop] = ft_atoi(data);
		else
			call_error("Invalid format:", tmp);
		while (ft_isdigit(*data))
			data++;
		loop++;
	}
	return ;
}

static t_color	fill_color(char *data)
{
	int		color[4];
	int		loop;
	char	*tmp;

	loop = 1;
	tmp = data;
	while (*data)
	{
		if (loop > 3)
			call_error("Invalid format:", tmp);
		while (*data && !ft_isdigit(*data))
			data++;
		if (ft_isdigit(*data))
			color[loop] = ft_atoi(data);
		else
			call_error("Invalid format:", tmp);
		if (color[loop] < 0 || color[loop] > 255)
			call_error("Color value must be between 0 and 255:", tmp);
		while (ft_isdigit(*data))
			data++;
		if (*data && *data != ',')
			call_error("Invalid format:", tmp);
		loop++;
	}
	return (create_color(0, color[1], color[2], color[3]));
}

static void		fill_data(char *data, char *line, t_map *map, t_graph *frame)
{
	if (*data == '\0')
		return ;
	if (ft_isdigit(*data))
		call_info("", line);
	else if (!ft_strcmp_to_space(data, "R"))
		fill_res(frame, data);
	else if (!ft_strcmp_to_space(data, "F"))
		map->color_floor = fill_color(data);
	else if (!ft_strcmp_to_space(data, "C"))
		map->color_roof = fill_color(data);
	else if (!ft_strcmp_to_space(data, "S"))
		map->sprite_entity = get_sprite(data, frame);
	else if (!ft_strcmp_to_space(data, "NO"))
		map->sprite_wall[0] = get_sprite(data, frame);
	else if (!ft_strcmp_to_space(data, "SO"))
		map->sprite_wall[1] = get_sprite(data, frame);
	else if (!ft_strcmp_to_space(data, "EA"))
		map->sprite_wall[2] = get_sprite(data, frame);
	else if (!ft_strcmp_to_space(data, "WE"))
		map->sprite_wall[3] = get_sprite(data, frame);
	else
		call_error("Invalid option:", data);
}

t_map			parse(char *filename, t_graph *frame)
{
	t_map	map;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		call_error("Invalid map path:", filename);
	while (get_next_line(fd, &line))
	{
		if (ft_isdigit(*is_part_map(line)))
			break ;
		fill_data(is_part_map(line), line, &map, frame);
		free(line);
	}
	free(line);
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	close(fd);
	get_map(&map, filename);
	return (map);
}
