/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:28:54 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/25 15:56:44 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*tmp;
	int		diff;
	size_t	decalage;

	tmp = ft_memchr(src, c, n);
	decalage = 0;
	if (tmp != NULL)
	{
		diff = tmp - src + 1;
		ft_memcpy(dest, src, diff);
		while (decalage * 16 < n)
			decalage++;
		return (dest + diff);
	}

	ft_memcpy(dest, src, n);
	return (NULL);
}
