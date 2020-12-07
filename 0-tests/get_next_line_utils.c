/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:28:12 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/05 22:23:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		*((char*)s) = '\0';
		s++;
		index++;
	}
}

void	*ft_calloc(int nmemb, int size)
{
	void	*new_tab;

	new_tab = malloc(size * nmemb);
	if (new_tab)
		ft_bzero(new_tab, size * nmemb);
	return (new_tab);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

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

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = ft_strlen(src);
	if (!src)
		return (NULL);
	ft_memcpy(dst, src, index + 1);
	return (dst);
}

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
