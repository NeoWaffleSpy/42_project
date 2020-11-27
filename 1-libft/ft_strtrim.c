/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:45:58 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/27 02:34:33 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

boolean	is_ref(char c, const char *ref)
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
	int		endroit;
	int		envers;

	if (!ref)
		return (ft_strdup(s1));
	endroit = 0;
	envers = ft_strlen(s1) - 1;
	trimmed = (char*)malloc(sizeof(char) * (envers + 2));
	while (is_ref(s1[endroit], ref))
		endroit++;
	if (!s1[endroit])
	{
		*trimmed = '\0';
		return (trimmed);
	}
	while (is_ref(s1[envers], ref))
		envers--;
	trimmed = ft_substr(s1, endroit, envers - endroit + 1);
	return (trimmed);
}
