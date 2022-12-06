# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncaba <ncaba@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 14:48:49 by ncaba             #+#    #+#              #
#    Updated: 2022/08/12 20:07:41 by ncaba            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Container
CXX			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
INC			=

SRC			=	main_test.cpp
SRCS		=	$(addprefix ./srcs/, $(SRC))
OBJ			=	$(SRCS:.cpp=.o)

HEADERFILES	=	vector.hpp
HEADERS		=	$(addprefix -I ./include/, $(HEADERFILES))

all: $(NAME) exec fclean

$(NAME): $(OBJ) 
	@$(CXX) $(OBJ) $(CPPFLAGS) $(INC) -o $(NAME)

%.o: %.c
	$(CXX) $(CPPFLAGS) $(HEADERS) -c -o $@ $<

exec:
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

unit_test:
	@echo "Starting tests"
	@make -s -C ./unit_tests/
	@./unit_tests/unit_test "[vector][stack]"
	@make -s fclean -C ./unit_tests/

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf a.out.dSYM

fclean: clean
	@/bin/rm -f $(NAME)
	@make -s fclean -C ./unit_tests/

re: clean $(NAME)

.PHONY: re fclean clean all
