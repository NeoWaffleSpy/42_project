# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2021/02/03 19:29:04 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INC			= -I . -I ./includes/libft/include/ -I./includes/minilibx-linux -L ./includes/libft/ -lft -L ./includes/minilibx-linux -lmlx -lbsd -lm -lX11 -lXext

SRCSFILES	=	test_top_down.c \
				init_struct.c \
				init_shapes.c \
				draw_pixel.c \
				draw_shapes.c \
				draw_triangle.c \
				sys_call.c \
				parse_file.c \
				parse_map.c \
				ft_strcmp_to_space.c \
				color_handler.c \
				debug_tools.c \
				raycasting.c \
				raycasting_utils.c \
				check_map.c \
				keybinding.c

SRCSDIR		= ./srcs/
SRCS		= $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS		= $(SRCS:.c=.o)

HEADERFILES	= cub3d.h
HEADERS		= $(addprefix -I ./include/, $(HEADERFILES))

LIBFT		= ./includes/libft/libft.a
MLX			= ./includes/minilibx-linux/libmlx.a

all: $(NAME)
	@echo "Compiled !"

$(LIBFT):
	@make -s -C ./includes/libft/

$(NAME): $(LIBFT) $(MLX) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) -g

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

$(MLX):
	@make -si -C ./includes/minilibx-linux

clean:
	@/bin/rm -f $(OBJS) $(BOBJS) $(OBJTEST)
	@/bin/rm -rf a.out.dSYM
	@make -s clean -C ./includes/libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make -s fclean -C ./includes/libft/
	@make -si clean -C ./includes/minilibx-linux

re: clean $(NAME)

retest: fclean maintest

.PHONY: re fclean clean all maintest bonus retest
