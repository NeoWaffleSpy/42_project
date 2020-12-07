/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:20:39 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/06 13:10:17 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int		ft_strclen(char *save)
{
	unsigned int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

static char				*ft_strrejoin(char *s1, char *s2, size_t len)
{
	char			*str;
	int				nb;
	char			*tmp;

	nb = ft_strlen(s1) + ++len;
	str = (char*)ft_calloc(sizeof(char), nb + 1);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	return (str - (str - tmp));
}

static char				*ft_savecpy(char *save)
{
	if (ft_strchr(save, '\n'))
	{
		ft_strcpy(save, ft_strchr(save, '\n') + 1);
		return (save);
	}
	if (ft_strclen(save) > 0)
	{
		ft_strcpy(save, ft_strchr(save, '\0'));
		return (save);
	}
	return (NULL);
}

int						get_next_line(int const fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*save[256];
	int				res;
	char			*ptr;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(save[fd]) && (save[fd] = (char*)ft_calloc(1, 1)) == NULL)
		return (-1);
	while (!(ft_strchr(save[fd], '\n')) &&
			(res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		ptr = save[fd];
		save[fd] = ft_strrejoin(ptr, buff, res);
		free(ptr);
	}
	*line = ft_substr(save[fd], 0, ft_strclen(save[fd]));
	ft_savecpy(save[fd]);
	if (res == 0)
		return (0);
	return (1);
}