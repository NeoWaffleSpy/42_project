/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:32:29 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/19 17:08:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_convert_char(t_flags flags, va_list params)
{
	char	c;
	char	*result;

	c = (char)va_arg(params, int);
	result = (char*)calloc(2, sizeof(char));
	*result = c;
	if (ft_strlen(result) == 0)
		flags.nb_spaces -= 1;
	ft_add_padd(&result, flags, CHAR);
	return (result);
}
