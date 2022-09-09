NAME	= microshell

CC		= clang

FLAGS	= -Wall -Wextra -Werror

FILES	= microshell.c

OBJS	= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean	:
	@rm -rf $(OBJS);

fclean	:	clean
	@rm -rf $(NAME)

re		:	fclean $(NAME)

.PHONY	: clean fclean re

%.o		:	%.c
	$(CC) $(FLAGS) -o $@ -c $<