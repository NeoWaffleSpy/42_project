/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:14:10 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/13 18:14:14 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*item;

	if (((item = (t_list *)malloc(sizeof(t_list))) == NULL))
		return (NULL);
	else
	{
		if (content == NULL)
		{
			item->content_size = 0;
			item->content = NULL;
		}
		else
		{
			if (((item->content = malloc(sizeof(content) * content_size))
				== NULL))
			{
				free(item);
				return (NULL);
			}
			item->content_size = content_size;
			item->content = ft_memcpy(item->content, content, content_size);
		}
		item->next = NULL;
	}
	return (item);
}
