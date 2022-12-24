/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:32:24 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/03 19:12:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../1-libft/libft.h"

int	main(int argc, char **argv)
{
	unsigned int		mask;
	int					complement;
	char				**addr;
	char				**tmp;
/*
	if (argc < 2)
		return (-1);
	tmp = ft_split(argv[1], '/');
	mask = ft_atoi(tmp[1]);
	addr = ft_split(tmp[0], '.');
	ft_free_all(tmp);
	complement = 32 - mask;
	mask = pow(2, mask);*/
	ft_putnbr(ft_pow(2, 4));
	ft_putchar('\n');
	ft_putnbr((2 << 4));
	ft_putchar('\n');
}
