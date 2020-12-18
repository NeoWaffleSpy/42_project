/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:32:29 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/17 13:01:29 by ncaba            ###   ########.fr       */
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
	ft_add_padd(&result, flags, CHAR);
	return (result);
}
