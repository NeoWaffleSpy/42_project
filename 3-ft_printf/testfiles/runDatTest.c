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

	ft_printf(" --- Return : %d at test 1\n",
	ft_printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d",
				a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf(" --- Return : %d at test 1\n",
	printf("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d",
				a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d at test 2\n",
	ft_printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d",
		a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf(" --- Return : %d at test 2\n",
	printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d",
		a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d at test 3\n",
	ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c",
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	printf(" --- Return : %d at test 3\n",
	printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c",
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d at test 4\n",
	ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s",
			NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	printf(" --- Return : %d at test 4\n",
	printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s",
			NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d at test 5\n",
	ft_printf("(null)"));
	printf(" --- Return : %d at test 5\n",
	printf("(null)"));
	printf("----------------------------------------------------------------\n");
	ft_printf(" --- Return : %d at test 6\n",
	ft_printf(""));
	printf(" --- Return : %d at test 6\n",
	printf(""));
}
