/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:29:10 by ncaba             #+#    #+#             */
/*   Updated: 2022/03/15 13:35:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		setZoom(double *zoom, double change)
{
	*zoom += change;
	if (*zoom < 1)
		*zoom = 1;
	else if (*zoom > 100)
		*zoom = 100;
}

static void		setContraste(double *zoom, double change)
{
	*zoom += change;
	if (*zoom < 0.1)
		*zoom = 0.1;
	else if (*zoom > 100)
		*zoom = 100;
}

void			update_key(t_struct *d_s)
{
	t_keys		*keys;
	double		delta;

	keys = &d_s->keys;
	delta = d_s->timer.delta;
	if (keys->arrowU_key.is_pressed == TRUE)
		setZoom(&d_s->map.zoom, 10 * delta);
	if (keys->arrowD_key.is_pressed == TRUE)
		setZoom(&d_s->map.zoom, -10 * delta);
	if (keys->plus_key.is_pressed == TRUE)
		setContraste(&d_s->map.contraste, 1 * delta);
	if (keys->minus_key.is_pressed == TRUE)
		setContraste(&d_s->map.contraste, -1 * delta);
}
