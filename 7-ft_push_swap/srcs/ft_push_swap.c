/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/21 17:54:52 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static void	create_pile(int ac, char **av, t_list **a)
{
	int	i;
	int	*tmp;

	i = 1;
	while (i < ac)
	{
		tmp = (int*)malloc(sizeof(int));
		*tmp = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(tmp));
		i++;
	}
}

void	print_iter(t_list *lst)
{
	int	*tmp;
	int	i;

	i = 0;
	if (ft_lstsize(lst) < 1)
	{
		call_info("empty list", "");
		return;
	}
	while (lst)
	{
		tmp = lst->content;
		ft_printf("-%3d", *tmp);
		lst = lst->next;
		i++;
	}
	ft_printf("\n", *tmp);
}

static void operate(t_list **a, t_list **b)
{
	if (check_sorted(a))
		return;
	else if (ft_lstsize(*a) == 2)
		sa(a, b, 1);
	else if (ft_lstsize(*a) == 3)
		sort_3(a, b);
	else if (ft_lstsize(*a) > 3)
		sort_big_new(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	if (argc <= 1)
		return(0);
	a = (t_list**)malloc(sizeof(int*));
	b = (t_list**)malloc(sizeof(int*));
	*a = 0;
	*b = 0;
	create_pile(argc, argv, a);
	operate(a, b);
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
}
