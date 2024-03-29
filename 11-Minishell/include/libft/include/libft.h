/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 23:18:35 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/28 18:01:04 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define TRUE 1
# define FALSE 0
# define MAXINT 2147483647
# define MININT -2147483648
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef int			t_boolean;

static t_list		*g_garbage;

void				*malloc_garbage(size_t size);
void				free_garbage(void *trash);
void				add_garbage(void *trash);
void				dump_trash(void);

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(char c);
int					ft_atoi(const char *nptr);
int					ft_pow(int chiffre, int expo);
char				*ft_itoa(int chiffre);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *dst, const char *src);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s1, const char *ref);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strljoin(const char *s1, const char *s2, int lencpy);
char				*ft_str_sp_join(const char *s1, const char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned in, char));
char				**ft_split(const char *str, char c);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t siez);
void				*ft_return0(void);
void				*ft_realloc(void *str, int new_size, int type);
void				ft_switch(void *p0, void *p1);
void				ft_cpy_tab(double dst[2], double src[2]);
void				ft_free_all(void **s);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list *alst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void*));
void				ft_lstadd_front(t_list **alst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(void*),
						void (*del)(void*));
t_list				*ft_lstdup(t_list *lst);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstget(t_list *lst, int i);
int					ft_lstsize(t_list *list);

#endif
