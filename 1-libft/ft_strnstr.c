/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:53:32 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/19 20:06:01 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t index;

	index = 0;
	if (!(*little))
		return ((char *)big);
	while (big && len > 0 && index < len)
	{
		index = 0;
		while (big && *big != *little && len > 0)
		{
			big++;
			len--;
		}
		while (little[index] && big[index] == little[index] && index < len)
		{
			index++;
		}
		if (little[index] == '\0')
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
