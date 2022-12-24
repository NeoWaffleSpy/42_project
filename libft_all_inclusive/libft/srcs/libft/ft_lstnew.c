/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:48 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/30 22:48:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*item;

	if (!(item = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	item->content = content;
	item->next = NULL;
	return (item);
}
