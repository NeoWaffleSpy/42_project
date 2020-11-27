/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:40:31 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/27 01:40:33 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_tab;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	new_tab = malloc(size * nmemb);
	if (new_tab)
		ft_bzero(new_tab, size * nmemb);
	return (new_tab);
}
