/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:23:05 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/05 22:19:40 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TRUE 1
# define FALSE 0
# define MAXINT 2147483647
# define MININT -2147483648
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int const fd, char **line);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(int nmemb, int size);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
