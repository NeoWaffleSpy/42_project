/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:49:51 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/19 21:23:57 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t index;

	index = 0;
	if (size == 0)
		return (0);
	while (*src && src[index] && index < size)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (index);
}
