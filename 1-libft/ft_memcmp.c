/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:04:02 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/20 23:37:56 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		
		if (((int*)s1)[index] - ((int*)s2)[index] != 0)
			return (((int*)s1)[index] - ((int*)s2)[index]);
		index++;
	}
	return (0);
}
