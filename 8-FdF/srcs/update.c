/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:44:47 by ncaba             #+#    #+#             */
/*   Updated: 2021/06/08 17:38:50 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	get_delta(t_timer *timer)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timer->new_t = ((double)time.tv_sec + ((double)time.tv_usec / 1000000));
	timer->delta = (timer->new_t - timer->old_t);
	timer->old_t = timer->new_t;
}

int			call_update(t_struct *data_struct)
{
	t_graph		*frame;

	frame = &data_struct->frame;
	get_delta(&data_struct->timer);
	update_key(data_struct);
	commit_img(frame, 0);
	return (0);
}
