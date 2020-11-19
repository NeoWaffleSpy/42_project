/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:27:48 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/19 21:29:12 by ncaba            ###   ########.fr       */
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
			tmp = (char*)s;
		s++;
	}
	if (c == (char)'\0')
		tmp = (char*)s;
	return (tmp);
}
