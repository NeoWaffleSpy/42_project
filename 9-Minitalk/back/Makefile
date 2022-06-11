# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2022/06/06 20:26:15 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C		= client
NAME_S		= server
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -I . -I ./include/libft/include/ -L ./include/libft/ -lft

SRCS_C		= client.c
SRCS_S		= server.c

SRCSDIR		= ./srcs/

SRC_C		= $(addprefix $(SRCSDIR), $(SRCS_C))
OBJ_C		= $(SRC_C:.c=.o)

SRC_S		= $(addprefix $(SRCSDIR), $(SRCS_S))
OBJ_S		= $(SRC_S:.c=.o)

HEADER_H_C	= client.h
HEADERS_C	= $(addprefix -I ./include/, $(HEADER_H_C))
HEADER_H_S	= server.h
HEADERS_S	= $(addprefix -I ./include/, $(HEADER_H_S))

LIBFT		= ./include/libft/libft.a

all: $(NAME_S) $(NAME_C)
	@echo "Compiled !"

$(LIBFT):
	@make -s -C ./include/libft/

$(NAME_S): $(LIBFT) $(OBJ_S) 
	@$(CC) $(OBJ_S) $(CFLAGS) $(INC) -o $(NAME_S) -g

$(NAME_C): $(LIBFT) $(OBJ_C) 
	@$(CC) $(OBJ_C) $(CFLAGS) $(INC) -o $(NAME_C) -g

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ_S) $(OBJ_C)
	@/bin/rm -rf a.out.dSYM
	@make -s clean -C ./include/libft/

fclean: clean
	@/bin/rm -f $(NAME_C) $(NAME_S)
	@make -s fclean -C ./include/libft/

re: clean $(NAME_C) $(NAME_S)

.PHONY: re fclean clean all bonus
