#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char *big, *small;

	big = "Une phrase aléatoire";
	small = "rase";
	printf("%s\n", ft_strnstr(big, small, 5));
	return 0;
}
