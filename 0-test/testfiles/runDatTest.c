#include "../include/ft_printf.h"

int		main(void)
{
	int		a = 2;
	int		b = -2;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
/*	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";*/

	ft_printf(" --- Return : %d\n",
	ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d",
				a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf(" --- Return : %d\n",
	printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d",
				a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d\n",
	ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d",
		a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf(" --- Return : %d\n",
	printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d",
		a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
}
