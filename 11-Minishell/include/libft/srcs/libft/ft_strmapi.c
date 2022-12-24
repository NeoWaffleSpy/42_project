/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:12:00 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/27 10:06:14 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned in, char))
{
	int		i;
	char	*mappedstr;

	if (s == NULL || f == NULL)
		return (NULL);
	mappedstr = malloc_garbage(sizeof(char) * (ft_strlen(s) + 1));
	if (mappedstr == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		mappedstr[i] = f(i, s[i]);
	}
	mappedstr[i] = '\0';
	return (mappedstr);
}
