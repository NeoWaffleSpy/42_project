# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2020/12/03 19:05:03 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3
SRCSFILES =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c
BNSFILES =	ft_free_all_bonus.c \
			ft_pow_bonus.c \
			ft_putchar_bonus.c \
			ft_putendl_bonus.c \
			ft_putnbr_bonus.c \
			ft_putstr_bonus.c \
			ft_return0_bonus.c \
			ft_strcat_bonus.c \
			ft_strcpy_bonus.c
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS = $(SRCS:.c=.o)
BSRCS = $(addprefix $(SRCSDIR), $(BNSFILES))
BOBJS = $(BSRCS:.c=.o)
HEADERS = libft.h
HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))

SRCTEST = test.c
OBJTEST = $(SRCTEST:.c=.o)
EXECTEST = a.out


all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) 
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJS) $(BOBJS) $(OBJTEST)
	/bin/rm -rf a.out.dSYM
	/bin/rm -f libft.gch
	/bin/rm -f $(EXECTEST)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean $(NAME)

retest: fclean maintest

.PHONY: re fclean clean all maintest bonus retest

maintest: bonus
	$(CC) -c $(SRCTEST) -I $(HEADERS)
	$(CC) $(OBJTEST) -o $(EXECTEST) -L. -lft

bonus: $(OBJS) $(BOBJS)
	ar rc $(NAME) $(OBJS) $(BOBJS)
	ranlib $(NAME)
