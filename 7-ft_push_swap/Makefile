# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2022/06/11 16:25:49 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_CHECK	= checker
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -I . -I ./include/libft/include/ -L ./include/libft/ -lft

SRCSFILES	=	create_pile.c \
				push.c \
				rev_rotate.c \
				rotate.c \
				sort_small.c \
				sorter.c \
				swap.c \
				sys_call.c

PUSH_SWAP	=	ft_push_swap.c
CHECKER		=	checker.c

SRCSDIR		=	./srcs/
SRCS		=	$(addprefix $(SRCSDIR), $(PUSH_SWAP)) \
				$(addprefix $(SRCSDIR), $(SRCSFILES))
SRCS_CHECK	=	$(addprefix $(SRCSDIR), $(CHECKER)) \
				$(addprefix $(SRCSDIR), $(SRCSFILES))

OBJS		=	$(SRCS:.c=.o)
OBJS_CHECK	=	$(SRCS_CHECK:.c=.o)

HEADERFILES	=	ft_push_swap.h
HEADERS		=	$(addprefix -I ./include/, $(HEADERFILES))

LIBFT		= ./include/libft/libft.a

all: $(NAME)
	@echo "Compiled !"

$(LIBFT):
	@make -s -C ./include/libft/

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) -g
	@echo "\033[0;33mUse command: \033[0;32mARG=\`ruby -e \"puts (0..499).to_a.shuffle.join(' ')\"\`\033[0m"

$(NAME_CHECK): $(LIBFT) $(OBJS_CHECK)
	@$(CC) $(OBJS_CHECK) $(CFLAGS) $(INC) -o $(NAME_CHECK) -g

both: $(NAME) $(NAME_CHECK)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJS) $(OBJS_CHECK)
	@/bin/rm -rf a.out.dSYM
	@make -s clean -C ./include/libft/

fclean: clean
	@/bin/rm -f $(NAME) $(NAME_CHECK)
	@make -s fclean -C ./include/libft/

re: clean $(NAME)

.PHONY: re fclean clean all both
