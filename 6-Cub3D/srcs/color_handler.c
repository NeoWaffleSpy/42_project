/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:23:41 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/20 15:29:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_color		create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int			get_t(t_color color)
{
	return (color & (0xFF << 24));
}

int			get_r(t_color color)
{
	return (color & (0xFF << 16));
}

int			get_g(t_color color)
{
	return (color & (0xFF << 8));
}

int			get_b(t_color color)
{
	return (color & 0xFF);
}
