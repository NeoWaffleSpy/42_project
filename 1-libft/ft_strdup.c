/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:10:29 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 16:06:52 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*newString;
	int		index;

	if (!s)
		return (NULL);
	newString = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newString)
		return (NULL);
	index = 0;
	while (s[index])
	{
		newString[index] = s[index];
		index++;
	}
	newString[index] = '\0';
	return (newString);
}
