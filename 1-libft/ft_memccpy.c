/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:28:54 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/22 02:19:09 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		*((char*)dest) = *((char*)src);
		if (*((char*)src) == (char)c)
			return (dest++);
		dest++;
		src++;
		index++;
	}
	return (NULL);
}
