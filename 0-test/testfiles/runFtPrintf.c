#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_printf(av[1], strtoul(av[2], 0, 10));
	else if (ac == 4)
		ft_printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	else
		printf("Usage: %s [Sring] [argument]", av[0]);
	printf("\n");
}
