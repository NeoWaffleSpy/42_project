/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/09 17:37:55 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static void	operate(t_list **a, t_list **b)
{
	if (check_sorted(a, 0))
		return ;
	else if (ft_lstsize(*a) == 2)
		sa(a, b, 1);
	else if (ft_lstsize(*a) == 3)
		sort_3(a, b);
	else if (ft_lstsize(*a) <= 5)
		sort_4_5(a, b);
	else if (ft_lstsize(*a) > 5)
		sort_big_index(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = malloc(sizeof(int *));
	b = malloc(sizeof(int *));
	*a = 0;
	*b = 0;
	if (create_pile(argc, argv, a))
	{
		ft_lstclear(a, free);
		ft_lstclear(b, free);
		free(a);
		free(b);
		call_error("Incorrect value", "");
	}
	if (ft_lstsize(*a))
		operate(a, b);
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
}
