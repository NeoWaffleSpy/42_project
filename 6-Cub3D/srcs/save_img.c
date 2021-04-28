/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:46:58 by ncaba             #+#    #+#             */
/*   Updated: 2021/04/28 16:34:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	fill_header(unsigned char header[14], int file_size)
{
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)file_size;
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
}

static void	fill_info(unsigned char info[40], int width, int height)
{
	info[0] = (unsigned char)40;
	info[4] = (unsigned char)width;
	info[5] = (unsigned char)(width >> 8);
	info[6] = (unsigned char)(width >> 16);
	info[7] = (unsigned char)(width >> 24);
	info[8] = (unsigned char)height;
	info[9] = (unsigned char)(height >> 8);
	info[10] = (unsigned char)(height >> 16);
	info[11] = (unsigned char)(height >> 24);
	info[12] = (unsigned char)1;
	info[14] = (unsigned char)24;
}

static int	save_colors(t_data *data, int fd)
{
	int				i;
	int				j;
	unsigned int	color;

	i = data->screen_size[1];
	while (i > 0)
	{
		j = 0;
		while (j < data->screen_size[0])
		{
			color = get_pixel(data, j, i);
			if (write(fd, &color, 3) == 0)
				call_error("error writing bmp image", "write color");
			j++;
		}
		i--;
	}
	return (0);
}

void		save_img(t_data *data)
{
	unsigned char	bmp_header[14];
	unsigned char	bmp_info[40];
	int				fd;

	if ((fd = creat("img.bmp", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		call_error("can't create file", "img.bmp");
	ft_bzero(bmp_header, 14);
	ft_bzero(bmp_info, 40);
	fill_header(bmp_header, 14 + 40 +
				(3 * data->screen_size[0] * data->screen_size[1]));
	fill_info(bmp_info, data->screen_size[0], data->screen_size[1]);
	if (write(fd, &bmp_header, 14) < 14)
		call_error("Error while saving .bmp file", "Header");
	if (write(fd, &bmp_info, 40) < 40)
		call_error("Error while saving .bmp file", "Info");
	if (save_colors(data, fd))
		call_error("Error while saving .bmp file", "Colors");
	close(fd);
	return ;
}
