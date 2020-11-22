/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:55:12 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 16:07:02 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*newStr;
	size_t	index;

	if (!s || (start > ft_strlen(s)))
		return (NULL);
	newStr = (char*)malloc(sizeof(char) * len + 1);
	index = 0;
	while (index < len && s[start + index])
	{
		newStr[index] = s[start + index];
		index++;
	}
	newStr[index] = '\0';
	return (newStr);
}
