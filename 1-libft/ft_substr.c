/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:55:12 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/28 16:57:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	index;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return ((char*)ft_calloc(1, 1));
	new_str = (char*)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		new_str[index] = s[start + index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
