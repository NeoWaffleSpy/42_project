/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:45:17 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/26 17:05:58 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rmspace(const char *nptr)
{
	boolean	is_space;
	int		counter;

	is_space = TRUE;
	counter = 0;
	while (is_space)
	{
		if (*nptr == ' ' || *nptr == '\n' || *nptr == '\v' ||
			*nptr == '\t' || *nptr == '\r' || *nptr == '\f' || *nptr == '+')
		{
			nptr++;
			counter++;
		}
		else
			is_space = FALSE;
	}
	return (counter);
}

int	ft_atoi(const char *nptr)
{
	boolean	is_negative;
	int		result;

	is_negative = FALSE;
	result = 0;
	nptr += rmspace(nptr);
	if (*nptr == '-')
	{
		nptr++;
		is_negative = TRUE;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (int)(*nptr - '0');
		nptr++;
	}
	if (is_negative)
		result *= -1;
	return (result);
}
