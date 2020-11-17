/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:53:32 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/17 16:33:49 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*	ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little)
		return ((char *)big);
	while (big)
	{
		int index;

		index = 0;
		while (big && *big != *little)
		{
			big++;
			len--;
		}
		while (little[index] != '\0' && big[index] == little[index] && index < len)
		{
			index++;
		}
		if (little[index] == '\0')
			return ((char *)big);
	}
	return (0);
}
