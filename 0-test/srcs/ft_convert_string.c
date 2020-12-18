/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:36:15 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/17 13:13:13 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_convert_string(t_flags flags, va_list params)
{
	char	*result;

	result = ft_strdup(va_arg(params, char*));
	ft_add_padd(&result, flags, STRING);
	return (result);
}
