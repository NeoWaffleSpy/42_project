/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/04 22:44:17 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static int	test_val(int i, char *lst)
{}

static int	create_pile(int ac, char **av, t_list **a)
{
	int	i;
	int	*tmp;
	char	**lst;

	i = 0;
	if (ac == 2)
	{
		lst = ft_split(av[1], ' ');
		while (lst[i])
		{
			tmp = (int*)malloc(sizeof(int));
			*tmp = ft_atoi(lst[i]);
			if (test_val(*tmp, lst[i]))
				return (1);
			ft_lstadd_back(a, ft_lstnew(tmp, 0));
			free(lst[i]);
			i++;
		}
		free(lst);
		return (0);
	}
	while (++i < ac)
	{
		tmp = (int*)malloc(sizeof(int));
		*tmp = ft_atoi(av[i]);
		if (test_val(*tmp, av[i]))
			return (1);
		ft_lstadd_back(a, ft_lstnew(tmp, 0));
	}
	return (0);
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
//		ft_printf("/%2d", lst->index);
		lst = lst->next;
		i++;
	}
	ft_printf("\n", *tmp);
}

static void operate(t_list **a, t_list **b)
{
	if (check_sorted(a, 0))
		return;
	else if (ft_lstsize(*a) == 2)
		sa(a, b, 1);
	else if (ft_lstsize(*a) == 3)
		sort_3(a, b);
	else if (ft_lstsize(*a) > 3)
		sort_big_index(a, b);
	print_iter(*a);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = (t_list**)malloc(sizeof(int*));
	b = (t_list**)malloc(sizeof(int*));
	*a = 0;
	*b = 0;
	create_pile(argc, argv, a);
	operate(a, b);
	print_iter(*a);
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
}
