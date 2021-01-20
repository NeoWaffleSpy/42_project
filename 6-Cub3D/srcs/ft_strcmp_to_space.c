/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_to_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:23:07 by ncaba             #+#    #+#             */
/*   Updated: 2021/01/20 14:47:36 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_strcmp_to_space(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((unsigned char)s1[index] == (unsigned char)s2[index] &&
			s1[index] && s2[index] &&
			s1[index] != ' ')
		index++;
	if ((!s1[index] || !s2[index]) && (s1[index] == ' ' || s2[index] == ' '))
		return (0);
	if ((unsigned char)s1[index] != (unsigned char)s2[index])
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	return (0);
}
