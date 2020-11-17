#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	printf("%d\n", ft_strncmp("aaa", "", 4));
	printf("%d\n", strncmp("aaa", "", 4));
	return 0;
}
