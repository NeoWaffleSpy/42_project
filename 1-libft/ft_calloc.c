/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:40:31 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/24 02:06:28 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	index;
	void	*new_tab;

	if (!size)
		return (NULL);
	index = 0;
	new_tab = malloc(size * nmemb);
	while (index < (nmemb * size))
	{
		*((char*)new_tab) = 0;
		index++;
	}
	return (new_tab);
}
