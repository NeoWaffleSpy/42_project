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
void test_strchr();
void test_strcpy();
void test_strdup();
void test_strjoin();
void test_strlcat();
void test_strlcpy();
void test_strlen();
void test_strmapi();
void test_strncmp();
void test_strnstr();
void test_strrchr();
void test_strtrim();
void test_substr();
void test_tolower();
void test_toupper();

int main(void)
{
	//test_atoi(); // OK
	//test_bzero(); // OK
	//test_calloc(); // OK
	//test_isalnum(); // OK
	//test_isalpha(); // OK
	//test_isascii(); // OK
	//test_isdigit(); // OK
	//test_isprint(); // OK
	//test_itoa(); // OK
	//test_memccpy(); // OK
	//test_memchr(); // OK
	//test_memcmp(); // OK
	//test_memcpy(); // OK
	//test_memset(); // OK
	//test_putchar_fd(); // OK
	//test_putendl_fd(); // OK
	//test_putnbr_fd(); // OK
	//test_putstr_fd(); // OK
	//test_split(); // OK mais pas de free a la fin ?
	//test_strcat(); // OK
	//test_strchr(); // OK
	//test_strcpy(); // OK
	//test_strdup(); // OK
	//test_strjoin(); // OK
	//test_strlcat(); // OK
	//test_strlcpy(); // OK
	//test_strlen(); // OK
	//test_strmapi(); // Flemme de tester
	//test_strncmp(); // OK
	//test_strnstr(); // OK
	//test_strrchr(); // OK
	//test_strtrim(); // OK
	//test_substr(); // OK
	//test_tolower(); // OK
	//test_toupper(); // OK
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
	char *s;
	int n;
	n = 5;
	s = ft_itoa(n);
	printf("%d -> %s\n", n, s);
	free(s);
	n = 154626;
	s = ft_itoa(n);
	printf("%d -> %s\n", n, s);
	free(s);
	n = 147852;
	s = ft_itoa(n);
	printf("%d -> %s\n", n, s);
	free(s);
	n = 0;
	s = ft_itoa(n);
	printf("%d -> %s\n", n, s);
	free(s);
	n = -147896523;
	s = ft_itoa(n);
	printf("%d -> %s\n", n, s);
	free(s);
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
	printf("%d - %d\n",
		memcmp("J'aime les bananes", "J'aime les banane", 19),
		ft_memcmp("J'aime les bananes", "J'aime les banane", 19));
	printf("%d - %d\n",
		memcmp("J'aime les banane", "J'aime les bananes", 19),
		ft_memcmp("J'aime les banane", "J'aime les bananes", 19));
	printf("%d - %d\n",
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
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('8', 1);
	ft_putchar_fd('\n', 1);
}

void test_putendl_fd()
{
	printf("--------->Test de ft_putendl_fd<---------\n");
	ft_putendl_fd("J'aime les bananes", 1);
	ft_putendl_fd("Je veut manger", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Faim", 1);
}

void test_putnbr_fd()
{
	printf("--------->Test de ft_putnbr_fd<---------\n");
	ft_putnbr_fd(1457825, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-875, 1);
	ft_putchar_fd('\n', 1);
}

void test_putstr_fd()
{
	ft_putstr_fd("--------->Test de ft_putstr_fd<---------\n", 1);
	ft_putstr_fd("Reussis\n", 1);
}

void test_split()
{
	printf("--------->Test de ft_split<---------\n");
	char **tab;
	tab = ft_split("Une phrase bien longue", ' ');
	while (*tab)
	{
		printf("%s\n", *tab);
		free(*tab);
		tab++;
	}
	tab = ft_split(" Une phrase bien longue", ' ');
	while (*tab)
	{
		printf("%s\n", *tab);
		free(*tab);
		tab++;
	}
	tab = ft_split("Une phrase bien longue ", ' ');
	while (*tab)
	{
		printf("%s\n", *tab);
		free(*tab);
		tab++;
	}
	tab = ft_split("Une    phrase    bien    longue", ' ');
	while (*tab)
	{
		printf("%s\n", *tab);
		free(*tab);
		tab++;
	}
}

void test_strcat()
{
	printf("--------->Test de ft_strcat<---------\n");
	char src2[] = " les bananes";
	char s2[] = "j'aime";
	ft_strcat(s2, src2);
	printf("ft_strcat -> %s\n", s2);
}

void test_strchr()
{
	printf("--------->Test de ft_strchr<---------\n");
	char *str = "J'aime les bananes";
	printf("   strchr -> %s\n", (char*)strchr(str, (int)'b'));
	printf("ft_strchr -> %s\n", (char*)ft_strchr(str, (int)'b'));
}

void test_strcpy()
{
	printf("--------->Test de ft_strcpy<---------\n");
	char *s1 = "Une phrase ?";
	char s2[13];
	bzero(s2, 13);
	strcpy(s2, s1);
	printf("   strcpy -> %s\n", s2);
	bzero(s2, 13);
	ft_strcpy(s2, s1);
	printf("ft_strcpy -> %s\n", s2);
}

void test_strdup()
{
	printf("--------->Test de ft_strdup<---------\n");
	char s[] = "J'aime les bananes";
	char *first = strdup(s);
	char *second = ft_strdup(s);
	printf("   strdup -> %s\nft_strdup -> %s\n", first, second);
	free(first);
	free(second);
}

void test_strjoin()
{
	printf("--------->Test de ft_strjoin<---------\n");
	char s1[] = "j'aime ";
	char s2[] = "les bananes";
	char *result = ft_strjoin(s1, s2);
	printf("ft_strjoin -> %s\n", result);
	free(result);
}

void test_strlcat()
{
	printf("--------->Test de ft_strlcat<---------\n");
	char src2[] = " les bananes";
	char s2[] = "j'aime";
	ft_strlcat(s2, src2, 10);
	printf("ft_strlcat -> %s\n", s2);
}

void test_strlcpy()
{
	printf("--------->Test de ft_strlcpy<---------\n");
	char *s1 = "Une phrase ?";
	char s2[13];
	bzero(s2, 13);
	strncpy(s2, s1, 13);
	printf("   strlcpy -> %s\n", s2);
	bzero(s2, 13);
	ft_strlcpy(s2, s1, 13);
	printf("ft_strlcpy -> %s\n", s2);
}

void test_strlen()
{
	printf("--------->Test de ft_strlen<---------\n");
	char s[] = "Une phrase";
	printf("%lu - %lu\n", strlen(s), ft_strlen(s));
}

void test_strmapi()
{
	printf("--------->Test de ft_strmapi<---------\n");
	printf("Niquez-vous\n");
}

void test_strncmp()
{
	printf("--------->Test de ft_strncmp<---------\n");
	printf("%d - %d\n",
		strncmp("J'aime les bananes", "J'aime les banane", 19),
		ft_strncmp("J'aime les bananes", "J'aime les banane", 19));
	printf("%d - %d\n",
		strncmp("J'aime les banane", "J'aime les bananes", 19),
		ft_strncmp("J'aime les banane", "J'aime les bananes", 19));
	printf("%d - %d\n",
		strncmp("J'aime les baqanes", "J'aime les banane", 19),
		ft_strncmp("J'aime les baqanes", "J'aime les banane", 19));
}

void test_strnstr()
{
	printf("--------->Test de ft_strnstr<---------\n");
	char big[] = "Une phrase aleatoire";
	char small[] = "ale";
	printf("   strnstr -> %s\n", strstr(big, small));
	printf("ft_strnstr -> %s\n", ft_strnstr(big, small, 20));
}

void test_strrchr()
{
	printf("--------->Test de ft_strrchr<---------\n");
	char *str = "J'aime les bananes";
	printf("   strrchr -> %s\n", (char*)strrchr(str, (int)'b'));
	printf("ft_strrchr -> %s\n", (char*)ft_strrchr(str, (int)'b'));
}

void test_strtrim()
{
	printf("--------->Test de ft_strtrim<---------\n");
	char s[] = "J'aime les bananes";
	char ref[] = "Jsn'e";
	char *result = ft_strtrim(s, ref);
	printf("\"%s\" with ref: %s\n", s, ref);
	printf("\"%s\"\n", result);
	free(result);
}

void test_substr()
{
	printf("--------->Test de ft_substr<---------\n");
	char s[] = "Une phrase aleatoire";
	char *result = ft_substr(s, 8, 12);
	printf("%s\n", result);
	free(result);
}

void test_tolower()
{
	printf("--------->Test de ft_tolower<---------\n");
	printf("A -> %c\n", (char)ft_tolower('A'));
	printf("a -> %c\n", (char)ft_tolower('a'));
	printf("( -> %c\n", (char)ft_tolower('('));
	printf("8 -> %c\n", (char)ft_tolower('8'));
	printf("F -> %c\n", (char)ft_tolower('F'));
}

void test_toupper()
{
	printf("--------->Test de ft_toupper<---------\n");
	printf("A -> %c\n", (char)ft_toupper('A'));
	printf("a -> %c\n", (char)ft_toupper('a'));
	printf("( -> %c\n", (char)ft_toupper('('));
	printf("8 -> %c\n", (char)ft_toupper('8'));
	printf("F -> %c\n", (char)ft_toupper('F'));
}
