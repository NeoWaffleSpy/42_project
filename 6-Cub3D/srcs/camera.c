/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:30 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/24 16:28:14 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	to_radian(float degree)
{
	return ((PI / 180) * degree);
}

float	d_cos(float degree)
{
	return (cos(to_radian(degree)));
}

float	d_sin(float degree)
{
	return (sin(to_radian(degree)));
}
