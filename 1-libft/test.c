#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	size_t taille;
	char *s;

	s = "ha";
	taille = ft_strlcpy(s, "Une phrase", 5);
	printf("%lu - %s\n", taille, s);
	return 0;
}
