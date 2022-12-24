#include "../include/ft_printf.h"

int		main(void)
{
	char c;

	c = 0;
	ft_printf("||%5c|%010c|%-10.*c||\n", 'a', 'b', 4, 'c');
	ft_printf("||%5x|%010X|%-10.*x||\n", 42, 153, 4, -6);
	ft_printf("||%5d|%010d|%-10.*d||\n", 42, 153, 4, -6);
	ft_printf("||%5s|%010s|%-10.*s||\n", "aa", "bbb", 4, "cccc");
	ft_printf("||%5u|%010u|%-10.*u||\n", 42, 153, 4, 6);
	ft_printf("||%%||\n");
	ft_printf("||%5p|%010p|%-10.*p||\n", &c, &c, 4, &c);
}
