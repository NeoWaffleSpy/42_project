/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:00:49 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/16 13:00:54 by pcadiot          ###   ########.fr       */
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
