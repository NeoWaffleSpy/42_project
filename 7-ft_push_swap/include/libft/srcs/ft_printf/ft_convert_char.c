/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:32:29 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/28 15:08:15 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static char		*inline_write(t_flags flags, int *len)
{
	int loop;

	loop = 0;
	if (flags.is_padded_left)
		ft_putchar('\0');
	while (loop < (flags.nb_spaces - 1))
	{
		ft_putchar(' ');
		loop++;
		(*len)++;
	}
	if (!flags.is_padded_left)
		ft_putchar('\0');
	(*len)++;
	return ((char*)calloc(2, sizeof(char)));
}

char			*ft_convert_char(t_flags flags, va_list params, int *len)
{
	char	c;
	char	*result;

	c = (char)va_arg(params, int);
	if (c == '\0')
		return (inline_write(flags, len));
	result = (char*)calloc(2, sizeof(char));
	*result = c;
	ft_add_padd(&result, flags, CHAR);
	return (result);
}
