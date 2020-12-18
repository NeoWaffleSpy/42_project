# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2020/12/18 03:02:39 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3

SRCSFILES	=	ft_printf.c \
				ft_parse.c \
				ft_convert_hexa.c \
				ft_convert_int.c \
				ft_convert_percent.c \
				ft_convert_pointer.c \
				ft_convert_string.c \
				ft_convert_unsigned.c \
				ft_convert_char.c \
				ft_multiflag.c \
				ft_flags_sorter.c \
				ft_spacing.c \
				ft_itoa_base.c

SRCSDIR		= ./srcs/
SRCS		= $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS		= $(SRCS:.c=.o)

HEADERFILES	= ft_printf.h
HEADERS		= $(addprefix -I ./include/, $(HEADERFILES))

TESTFILES	=	runOnlyInt.c \
				runListbreaker.c \
				runComparative.c \
				runFtPrintf.c \
				runPrintf.c \
				runAllTest.c \
				runDatTest.c

TESTDIR		= ./testfiles/
SRCSTEST	= $(addprefix $(TESTDIR), $(TESTFILES))
OBJTEST		= $(SRCSTEST:.c=.o)
EXECTEST	= $(OBJTEST:%.o=%.out)

LIBFT		= ./libft/libft.a

all: $(NAME)
	@echo "Compiled !"

$(LIBFT):
	@make bonus -C libft

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $<

%.out: %.o $(NAME)
	@$(CC) $(CFLAGS) -o $@ $< $(NAME)
	@echo "$(notdir $@) has been created !"

clean:
	@echo "Cleaning"
	@/bin/rm -f $(OBJS) $(BOBJS) $(OBJTEST)
	@/bin/rm -rf a.out.dSYM
	@/bin/rm -f libft.gch
	@/bin/rm -f *.out
	@make clean -C libft

fclean: clean
	@echo "Big Cleaning"
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a

re: fclean $(NAME)

retest: fclean maintest

maintest: $(EXECTEST)
	@mv testfiles/*.out .
	@echo "Compiled with executable !"

.PHONY: re fclean clean all maintest bonus retest
