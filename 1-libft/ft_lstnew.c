/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:48 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/28 01:38:51 by ncaba            ###   ########.fr       */
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
