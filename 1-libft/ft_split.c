/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:07:05 by ncaba             #+#    #+#             */
/*   Updated: 2020/11/30 16:54:01 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_split(const char *str, char c)
{
	int		nb_split;

	nb_split = 0;
	while (*str)
	{
		while (*str && *str == c)
		{
			str++;
		}
		if (*str)
		{
			nb_split++;
			while (*str && *str != c)
			{
				str++;
			}
		}
	}
	return (nb_split);
}

static char	**free_all(char **tab, int countdown)
{
	while (countdown)
	{
		countdown--;
		free(tab[countdown]);
	}
	free(tab);
	return (NULL);
}

char		**ft_split(const char *str, char c)
{
	char	**tab;
	int		index;
	int		index_tab;

	index_tab = 0;
	if (!str)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (get_nb_split(str, c) + 1))))
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			index = 0;
			while (str[index] && str[index] != c)
				index++;
			if (!(tab[index_tab++] = ft_substr(str, 0, index)))
				return (free_all(tab, index_tab));
			str += index;
		}
	}
	tab[index_tab] = 0;
	return (tab);
}
