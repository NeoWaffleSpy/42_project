#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_printf(av[1], NULL);
		ft_putchar('\n');
		printf(av[1], NULL);
		printf("\n");
	}
	else
		printf("Usage: %s [Sring] [argument]", av[0]);
}
