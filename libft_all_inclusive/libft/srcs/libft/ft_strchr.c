/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 21:27:48 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/26 00:23:27 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	loop;

	loop = 0;
	while (s[loop])
	{
		if (s[loop] == (char)c)
			return ((char*)&s[loop]);
		loop++;
	}
	if (s[loop] == (char)c)
		return ((char*)&s[loop]);
	return (NULL);
}
