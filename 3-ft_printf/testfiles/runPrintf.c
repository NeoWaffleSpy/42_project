#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf(av[1], strtoul(av[2], 0, 10));
	else
		printf("Usage: %s [Sring] [argument]", av[0]);
	printf("\n");
}
