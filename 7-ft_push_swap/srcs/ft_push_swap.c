/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/06 14:00:21 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static void	create_pile(t_list **a, int ac, char **av)
{
	int i;

	i = 2;
	*a = ft_lstnew(av[1]);
	while (i < ac)
	{
		ft_lstadd_back(ft_lstnew(av[i]));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc <= 1)
		return(0);
	create_pile(a, argc, argv);
	ft_lstiter(a, ft_printf())
	ft_lstclear(a, NULL);
}
