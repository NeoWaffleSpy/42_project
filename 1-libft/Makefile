# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2020/11/21 17:33:38 by ncaba            ###   ########.fr        #
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
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS = $(SRCS:.c=.o)
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
	/bin/rm -f *.o
	/bin/rm -rf a.out.dSYM
	/bin/rm -f *.gch
	/bin/rm -f $(EXECTEST)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

prepare: fclean
	rm -f main_.c main_test_.c svtest_.c svtest_.h test_.c

.PHONY: re fclean clean

check: all
	#$(CC) $(CFLAGS) -$(CFLAGS) c -Wall -Wextra -Werror $(SRCTEST) -I $(HEADER)
	#$(CC) $(OBJTEST) -L. -lft
	$(CC) $(CFLAGS) $(SRCTEST) -L. -lft -I $(HEADERS)

checkfclean: fclean
	/bin/rm -f $(OBJTEST)
	/bin/rm -f a.out

recheck: checkfclean check

rm: checkfclean

retest: recheck
	./a.out

maintest: all
	$(CC) -c $(SRCTEST) -I $(HEADERS)
	$(CC) $(OBJTEST) -o $(EXECTEST) -L. -lft
