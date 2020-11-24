/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:17:35 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/24 01:42:46 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}
