/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:24:36 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/24 02:17:36 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcat(char *dst, const char *src)
{
	size_t index;

	index = 0;
	if (!src)
		return (0);
	while (dst[index])
	{
		index++;
	}
	while (*src)
	{
		dst[index] = *src;
		index++;
		src++;
	}
	dst[index] = '\0';
	return (index);
}
