#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test_atoi();
void test_bzero();
void test_calloc();
void test_isalnum();
void test_isalpha();
void test_isascii();
void test_isdigit();
void test_isprint();
void test_itoa();
void test_memccpy();
void test_memchr();
void test_memcmp();
void test_memcpy();
void test_memset();
void test_putchar_fd();
void test_putendl_fd();
void test_putnbr_fd();
void test_putstr_fd();
void test_split();
void test_strcat();

int main(void)
{
	test_atoi(); // OK
	test_bzero(); // OK
	test_calloc(); // OK
	test_isalnum(); // OK
	test_isalpha(); // OK
	test_isascii(); // OK
	test_isdigit(); // OK
	test_isprint(); // OK
	test_memccpy(); // OK
	test_memchr(); // OK
	test_memcmp(); // OK
	test_memcpy(); // OK
	test_memset(); // OK
	test_strcat(); // OK
	return 0;
}

void test_atoi()
{
	printf("--------->Test de ft_atoi<---------\n");
	printf("%d -> %d\n", atoi("  -457"), ft_atoi("  -457"));
	printf("%d -> %d\n", atoi("  +87 456"), ft_atoi("  +87 456"));
	printf("%d -> %d\n", atoi("  457651qgq365e31"), ft_atoi("  457651qgq365e31"));
	printf("%d -> %d\n", atoi(""), ft_atoi(""));
}

void test_bzero()
{
	printf("--------->Test de ft_bzero<---------\n");
	char str[] = "Une phrase";
	char str2[] = "Une phrase";
	bzero(str, 10);
	ft_bzero(str2, 10);
	printf("P1:%s\nP2:%s\n", str, str2);
}

void test_calloc()
{
	printf("--------->Test de ft_calloc<---------\n");
	char *str = "haha";
	str = (char*)ft_calloc(4, sizeof(char));
	printf("%c%c%c%c\n", str[0], str[1], str[2], str[3]);
	free(str);
}

void test_isalnum()
{
	printf("--------->Test de ft_isalnum<---------\n");
	printf("%d -> %d\n", isalnum('5'), ft_isalnum('5'));
	printf("%d -> %d\n", isalnum('a'), ft_isalnum('a'));
	printf("%d -> %d\n", isalnum('A'), ft_isalnum('A'));
	printf("%d -> %d\n", isalnum((char)127), ft_isalnum((char)127));
	printf("%d -> %d\n", isalnum('@'), ft_isalnum('@'));
}

void test_isalpha()
{
	printf("--------->Test de ft_isalpha<---------\n");
	printf("%d -> %d\n", isalpha('5'), ft_isalpha('5'));
	printf("%d -> %d\n", isalpha('a'), ft_isalpha('a'));
	printf("%d -> %d\n", isalpha('A'), ft_isalpha('A'));
	printf("%d -> %d\n", isalpha((char)127), ft_isalpha((char)127));
	printf("%d -> %d\n", isalpha('@'), ft_isalpha('@'));
}

void test_isascii()
{
	printf("--------->Test de ft_isascii<---------\n");
	printf("%d -> %d\n", isascii('5'), ft_isascii('5'));
	printf("%d -> %d\n", isascii('a'), ft_isascii('a'));
	printf("%d -> %d\n", isascii('A'), ft_isascii('A'));
	printf("%d -> %d\n", isascii((char)127), ft_isascii((char)127));
	printf("%d -> %d\n", isascii('@'), ft_isascii('@'));
}

void test_isdigit()
{
	printf("--------->Test de ft_isdigit<---------\n");
	printf("%d -> %d\n", isdigit('5'), ft_isdigit('5'));
	printf("%d -> %d\n", isdigit('a'), ft_isdigit('a'));
	printf("%d -> %d\n", isdigit('A'), ft_isdigit('A'));
	printf("%d -> %d\n", isdigit((char)127), ft_isdigit((char)127));
	printf("%d -> %d\n", isdigit('@'), ft_isdigit('@'));
}

void test_isprint()
{
	printf("--------->Test de ft_isprint<---------\n");
	printf("%d -> %d\n", isprint('5'), ft_isprint('5'));
	printf("%d -> %d\n", isprint('a'), ft_isprint('a'));
	printf("%d -> %d\n", isprint('A'), ft_isprint('A'));
	printf("%d -> %d\n", isprint((char)127), ft_isprint((char)127));
	printf("%d -> %d\n", isprint('@'), ft_isprint('@'));
}

void test_itoa()
{
	printf("--------->Test de ft_itoa<---------\n");

}

void test_memccpy()
{
	printf("--------->Test de ft_memccpy<---------\n");
	char *s1 = "Une phrase ?";
	char s2[13];
	bzero(s2, 13);
	memccpy(s2, s1, (int)'h', 13);
	printf("   memccpy -> %s\n", s2);
	bzero(s2, 13);
	ft_memccpy(s2, s1, (int)'h', 13);
	printf("ft_memccpy -> %s\n", s2);
}

void test_memchr()
{
	printf("--------->Test de ft_memchr<---------\n");
	char *str = "J'aime les bananes";
	printf("   memchr -> %s\n", (char*)memchr(str, (int)'b', 17));
	printf("ft_memchr -> %s\n", (char*)ft_memchr(str, (int)'b', 17));
}

void test_memcmp()
{
	printf("--------->Test de ft_memcmp<---------\n");
	printf("1/%d - %d\n",
		memcmp("J'aime les bananes", "J'aime les banane", 19),
		ft_memcmp("J'aime les bananes", "J'aime les banane", 19));
	printf("1/%d - %d\n",
		memcmp("J'aime les banane", "J'aime les bananes", 19),
		ft_memcmp("J'aime les banane", "J'aime les bananes", 19));
	printf("1/%d - %d\n",
		memcmp("J'aime les baqanes", "J'aime les banane", 19),
		ft_memcmp("J'aime les baqanes", "J'aime les banane", 19));
}

void test_memcpy()
{
	printf("--------->Test de ft_memcpy<---------\n");
	char *s1 = "Une phrase ?";
	char s2[13];
	bzero(s2, 13);
	memcpy(s2, s1, 13);
	printf("   memcpy -> %s\n", s2);
	bzero(s2, 13);
	ft_memcpy(s2, s1, 13);
	printf("ft_memcpy -> %s\n", s2);
}

void test_memset()
{
	printf("--------->Test de ft_memset<---------\n");
	char str[] = "Une phrase";
	char str2[] = "Une phrase";
	memset(str, (int)'b', strlen(str));
	ft_memset(str2, (int)'b', ft_strlen(str2));
	printf("P1:%s\nP2:%s\n", str, str2);
}

void test_putchar_fd()
{
	printf("--------->Test de ft_putchar_fd<---------\n");
}

void test_putendl_fd()
{
	printf("--------->Test de ft_putendl_fd<---------\n");
}

void test_putnbr_fd()
{
	printf("--------->Test de ft_putnbr_fd<---------\n");
}

void test_putstr_fd()
{
	printf("--------->Test de ft_putstr_fd<---------\n");
}

void test_split()
{
	printf("--------->Test de ft_split<---------\n");
}

void test_strcat()
{
	printf("--------->Test de ft_strcat<---------\n");
	char src2[] = " les bananes";
	char s2[] = "j'aime";
	ft_strcat(s2, src2);
	printf("ft_strcat -> %s\n", s2);
}
