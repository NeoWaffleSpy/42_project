/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:54:57 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/16 12:52:57 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	putstr_free(char *str)
{
	int len;

	len = (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int			ft_printf(char *str, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, str);
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar(*str);
			str++;
			result++;
		}
		if (*str)
			result += putstr_free(ft_parse(&str, params));
	}
	va_end(params);
	return (result);
}
