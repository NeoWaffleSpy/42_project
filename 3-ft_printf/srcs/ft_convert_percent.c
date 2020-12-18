/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:35:28 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/17 15:55:20 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_convert_percent()
{
	char	*result;

	result = (char*)calloc(2, sizeof(char));
	result[0] = '%';
	return (result);
}
