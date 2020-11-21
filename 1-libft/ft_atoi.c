/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:45:17 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 00:03:47 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	boolean	isSpace;
	boolean	isNegative;
	int		result;

	isSpace = TRUE;
	isNegative = FALSE;
	result = 0;
	while (isSpace)
	{
		if (*nptr == ' ' ||
			*nptr == '\n' ||
			*nptr == '\v' ||
			*nptr == '\t' ||
			*nptr == '\r' ||
			*nptr == '\f' ||
			*nptr == '+')
		{
			nptr++;
		}
		else
		{
			isSpace = FALSE;
		}
	}
	if (*nptr == '-')
	{
		nptr++;
		isNegative = TRUE;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (int)(*nptr - '0');
		nptr++;
	}
	if (isNegative)
		result *= -1;
	return (result);
}
