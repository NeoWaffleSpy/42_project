/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:27:48 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/26 00:09:43 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (!tmp)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if (c == (char)'\0')
		return ((char*)s);
	return (NULL);
}
