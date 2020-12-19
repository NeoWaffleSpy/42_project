#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_printf(av[1], '\0');
		ft_putchar('\n');
		printf(av[1], '\0');
		printf("\n");
	}
	else
		printf("Usage: %s [Sring] [argument]", av[0]);
}
