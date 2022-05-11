/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/11 23:31:56 by ncaba            ###   ########.fr       */
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

static void	print_iter(t_list *lst)
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
	sa(a, b);
	pb(a, b);
	ra(a, b);
	rra(a, b);
	if (check_sorted(a))
		call_info("List sorted", "");
	else
		call_info("List not sorted", "");
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	(void)print_iter;
	a = (t_list**)malloc(sizeof(int*));
	b = (t_list**)malloc(sizeof(int*));
	*a = 0;
	*b = 0;
	if (argc <= 1)
		return(0);
	create_pile(argc, argv, a);
	operate(a, b);
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
}
