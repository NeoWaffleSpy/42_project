/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:20:17 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/20 23:28:45 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		index;
	void	*tmp;

	index = 0;
	tmp = NULL;
	while (index < n)
	{
		if (*((int*)s) == c)
			tmp = (void*)s;
		s++;
		index++;
	}
	return (tmp);
}
