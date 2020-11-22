/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:18:35 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 17:32:40 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define NULL 0
# define TRUE 1
# define FALSE 0

typedef unsigned long int size_t;
typedef int boolean;

size_t			ft_strlen(const char *s);
size_t			ft_strcpy(char *dst, const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strcat(char *dst, const char *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s1, const char *ref);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t siez);
void			ft_bzero(void *s, size_t n);

#endif
