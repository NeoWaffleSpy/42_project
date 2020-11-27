/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:24:02 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/27 03:16:28 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		max_len(int chiffre)
{
	int		len;
	int		string_len;

	len = 1;
	string_len = 1;
	while ((len * 10) <= chiffre)
	{
		len *= 10;
		string_len++;
	}
	return (string_len);
}

char	*return_0(char *s)
{
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int chiffre)
{
	char	*str;
	int		len;
	int		string_len;

	str = (char*)malloc(sizeof(char) * max_len(chiffre) + 2);
	if (chiffre == 0)
		return (return_0(str));
	string_len = 0;
	if (chiffre < 0)
	{
		str[string_len] = '-';
		string_len++;
		chiffre *= -1;
	}
	while (chiffre)
	{
		len = 1;
		while ((len * 10) <= chiffre)
			len *= 10;
		str[string_len] = ((char)(chiffre / len) + '0');
		string_len++;
		chiffre %= len;
	}
	str[string_len] = '\0';
	return (str);
}
