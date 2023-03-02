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

NAME		= Materia
CXX			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
INC			= -I ./

SRC			=	main.cpp \
				AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				MateriaSource.cpp

#SRC			=	$(addprefix ./srcs/, $(SRCS))
OBJ			=	$(SRC:.cpp=.o)

HEADERS		=	AMateria.hpp \
				Character.hpp \
				Cure.hpp \
				Ice.hpp \
				MateriaSource.hpp
#HEADERS		=	$(addprefix -I ./include/, $(HEADERFILES))

all: $(NAME)
	@echo "Compiled !"

$(NAME): $(OBJ) 
	@$(CXX) $(OBJ) $(CPPFLAGS) $(INC) -o $(NAME) -g

%.o: %.c
	$(CXX) $(CPPFLAGS) $(HEADERS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf a.out.dSYM

fclean: clean
	@/bin/rm -f $(NAME)

re: clean $(NAME)

.PHONY: re fclean clean all norminette vtest
