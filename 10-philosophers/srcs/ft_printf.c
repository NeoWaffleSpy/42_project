/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:33:03 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/01 16:48:52 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == MININT)
	{
		ft_putnbr_fd(MININT / 10, fd);
		ft_putnbr_fd(-(MININT % 10), fd);
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

void	ft_printf(int time, int philo, char *str)
{
	write(1, "| ", 2);
	ft_putnbr_fd(time, 1);
	write(1, " | ", 3);
	ft_putnbr_fd(philo, 1);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
}
