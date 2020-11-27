/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:24:45 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/27 21:41:33 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putnbr_fd2(int n, int fd)
{
	char *s;

	s = ft_itoa(n);
	ft_putstr_fd(s, fd);
	free(s);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == MININT)
	{
		ft_putnbr_fd(MININT / 10, fd);
		ft_putnbr_fd(MININT % 10, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		ft_putchar_fd('0' + n, fd);
	}
}
