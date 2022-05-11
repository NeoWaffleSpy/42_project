# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2022/05/11 23:30:14 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_push_swap
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -I . -I ./include/libft/include/ -L ./include/libft/ -lft

SRCSFILES	=	ft_push_swap.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sorter.c \
				swap.c \
				sys_call.c \

SRCSDIR		= ./srcs/
SRCS		= $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS		= $(SRCS:.c=.o)

HEADERFILES	= ft_push_swap.h
HEADERS		= $(addprefix -I ./include/, $(HEADERFILES))

LIBFT		= ./include/libft/libft.a

all: $(NAME)
	@echo "Compiled !"

$(LIBFT):
	@make -s -C ./include/libft/

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS) $(BOBJS) $(OBJTEST)
	@/bin/rm -rf a.out.dSYM
	@make -s clean -C ./include/libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make -s fclean -C ./include/libft/

re: clean $(NAME)

.PHONY: re fclean clean all bonus
