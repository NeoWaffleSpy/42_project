/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:23:07 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/17 13:41:10 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
	int index;
	int compare;

	index = 0;

	while(s1 && s2 && s1[index] && s2[index]) {
		compare = s1[index] - s2[index];
		if (compare < 0)
			return -1;
		if (compare > 0)
			return 1;
		index++;
	}

	compare = s1[index] - s2[index];
	if (compare < 0)
		return -1;
	if (compare > 0)
		return 1;
	return 0;
}
