/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:35:28 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/28 14:46:23 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_convert_percent(t_flags flags)
{
	char	*result;

	result = (char*)calloc(2, sizeof(char));
	result[0] = '%';
	ft_add_space(&result, flags, PERCENT);
	ft_add_padd(&result, flags, PERCENT);
	return (result);
}
