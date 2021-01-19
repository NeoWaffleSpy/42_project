/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:09:55 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/19 22:44:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	fill_data(char *data, char *line, t_map map)
{
	char	**data_split;

	(void)map;
	if (*data == '\0')
		return ;
	if (ft_isdigit(*data))
		return (call_info("", line));
	data_split = ft_split(data, ' ');
	if (!ft_strcmp(data_split[0], "R"))
		return (call_info("Resolution:", data));
	else if (!ft_strcmp(data_split[0], "F"))
		return (call_info("Floor color:", data));
	else if (!ft_strcmp(data_split[0], "C"))
		return (call_info("Roof color:", data));
	else if (!ft_strcmp(data_split[0], "S"))
		return (call_info("Entity sprite:", data));
	else if (!ft_strcmp(data_split[0], "NO"))
		return (call_info("North wall sprite:", data));
	else if (!ft_strcmp(data_split[0], "SO"))
		return (call_info("South wall sprite:", data));
	else if (!ft_strcmp(data_split[0], "EA"))
		return (call_info("East wall sprite:", data));
	else if (!ft_strcmp(data_split[0], "WE"))
		return (call_info("Weast wall sprite:", data));
	else
		call_error("Invalid option:", data);
}

t_map		parse(char *filename)
{
	t_map	map;
	int		fd;
	char	*line;

	map.resolution[0] = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		call_error("Invalid map path:", filename);
	while (get_next_line(fd, &line))
		fill_data(ft_strtrim(line, " "), line, map);
	return (map);
}
