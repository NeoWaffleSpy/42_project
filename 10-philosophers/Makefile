# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2022/07/09 18:15:13 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philosophers
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -I . -lpthread

SRCSFILES	=	main.c \
				init.c \
				routine.c \
				routine_utils.c \
				sys_call.c \
				ft_atoi.c

SRCSDIR		= ./srcs/
SRCS		= $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS		= $(SRCS:.c=.o)

HEADERFILES	= philosophers.h
HEADERS		= $(addprefix -I ./include/, $(HEADERFILES))

all: $(NAME)
	@echo "Compiled !"

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf a.out.dSYM

fclean: clean
	@/bin/rm -f $(NAME)

re: clean $(NAME)

.PHONY: re fclean clean all bonus
