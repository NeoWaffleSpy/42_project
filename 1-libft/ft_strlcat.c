/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:08:33 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/19 21:23:50 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;

	index = 0;
	if (size == 0)
		return (0);
	while (dst[index])
	{
		index++;
		size++;
	}
	while (*src && index < size)
	{
		dst[index] = *src;
		index++;
		src++;
	}
	dst[index] = '\0';
	return (index);
}
