/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:08:33 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/26 01:02:18 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;
	size_t index2;

	index = 0;
	index2 = 0;
	if (size == 0)
		return (0);
	while (dst[index])
		index++;
	while (src[index2] && index < size - 1)
		dst[index++] = src[index2++];
	if (size != 0 && size <= ft_strlen(dst))
		dst[index] = '\0';
	if (size > ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + ft_strlen(dst));
}
