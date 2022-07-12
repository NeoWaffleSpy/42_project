/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:35:07 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/11 13:56:54 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	rmspace(const char *nptr)
{
	t_boolean	is_space;
	int			counter;

	is_space = TRUE;
	counter = 0;
	while (is_space)
	{
		if (*nptr == ' ' || *nptr == '\n' || *nptr == '\v'
			|| *nptr == '\t' || *nptr == '\r' || *nptr == '\f')
		{
			nptr++;
			counter++;
		}
		else
			is_space = FALSE;
	}
	return (counter);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((unsigned char)s1[index] == (unsigned char)s2[index]
		&& s1[index] && s2[index] && index < n - 1)
		index++;
	if (index < n)
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_atoi_2(const char *nptr)
{
	t_boolean	is_negative;
	int			result;

	is_negative = FALSE;
	result = 0;
	nptr += rmspace(nptr);
	if (ft_strncmp(nptr, "-2147483648", 12) == 0)
		return (-2147483648);
	if (*nptr == '-')
	{
		nptr++;
		is_negative = TRUE;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
	{
		if (result * 10 + (int)(*nptr - '0') < result)
			return (is_negative - 1);
		result = result * 10 + (int)(*nptr - '0');
		nptr++;
	}
	if (is_negative)
		result *= -1;
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	ret;

	i = 0;
	if (nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (-1);
		i++;
	}
	ret = ft_atoi_2(nptr);
	if (i > 11 || (ft_isdigit(nptr[0]) && ret < 0)
		|| (nptr[0] == '-' && ret == 0))
	{
		call_error("Invalid value:", (char *)nptr);
		exit(0);
	}
	return (ret);
}
