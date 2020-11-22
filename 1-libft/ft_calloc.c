/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:40:31 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/21 16:07:00 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t index;
	void	*newTab;

	if (!size)
		return (NULL);
	index = 0;
	newTab = malloc(size * nmemb);
	while (index < (nmemb * size))
	{
		*((char*)newTab) = 0;
		index++;
	}
	return (newTab);
}
