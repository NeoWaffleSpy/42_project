/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:59:08 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/25 18:00:15 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove2(void *dst, const void *src, size_t n)
{
	unsigned char	tmp[n];

	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (a > b)
	{
		while (i < len)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dst);
}

