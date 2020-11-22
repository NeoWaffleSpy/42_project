/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:45:58 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 17:33:53 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

boolean	isRef(char c, const char *ref)
{
	while (*ref)
	{
		if (c == *ref)
		{
			return (TRUE);
		}
		ref++;
	}
	return (FALSE);
}

char	*ft_strtrim(const char *s1, const char *ref)
{
	char	*trimmed;
	char	*tmp;
	int		index;
	size_t	len;
	char	*pointeur;

	if (!ref)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + 1;
	trimmed = (char*)malloc(sizeof(char) * len);
	tmp = (char*)malloc(sizeof(char) * len);
	ft_bzero(tmp, len);
	index = 0;
	pointeur = trimmed;
	while (isRef(*s1, ref))
	{
		s1++;
	}
	while (*s1)
	{
		if (!isRef(*s1, ref))
		{
			ft_strcat(trimmed, tmp);
			*trimmed = s1[index];
			trimmed++;
			ft_bzero(tmp, len);
		}
		else
			tmp[ft_strlen(tmp)] = *s1;
		s1++;
	}
	*trimmed = '\0';
	trimmed = pointeur;
	free(tmp);
	return (trimmed);
}
