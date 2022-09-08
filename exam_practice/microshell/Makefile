NAME	= microshell
CC		= gcc

SRCS	= microshell.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(OBJS) -o $(NAME)

.PHONY all

%.o: %.c