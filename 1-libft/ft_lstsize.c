/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:28:35 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/30 20:46:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *list)
{
	int	size;

	if (!list)
		return (0);
	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
