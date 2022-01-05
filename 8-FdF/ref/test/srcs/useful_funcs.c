/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:30:40 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:30:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	chaos(void *fate)
{
	if (fate == NULL)
		exit(EXIT_FAILURE);
}

void	msg_exit(char* s, void* sortie)
{
	ft_printf(s, sortie);
	exit(1);
}

void	ft_exit(t_data *data)
{
	while (--data->map.size.y != (typeof(data->map.size.y))-1)
	{
		free(data->zbuff[data->map.size.y]);
		free(data->map.heightmap[data->map.size.y]);
	}
	free(data->zbuff);
	free(data->map.heightmap);
	free(data);
	exit(EXIT_SUCCESS);
}
