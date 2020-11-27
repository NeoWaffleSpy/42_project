/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:26:01 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/27 23:26:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstdup(t_list *lst)
{
	t_list	*link;
	t_list	*first;

	if (!lst)
		return (NULL);
	first = ft_lstnew(lst->content, lst->content_size);
	lst = lst->next;
	link = first;
	while (lst)
	{
		link->next = ft_lstnew(lst->content, lst->content_size);
		if (!link)
			return (NULL);
		link = link->next;
		lst = lst->next;
	}
	return (first);
}
