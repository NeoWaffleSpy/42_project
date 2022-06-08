/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/06 21:57:54 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static int	test_val(int i, char *lst, t_list **a)
{
	int	j;

	if (ft_strlen(lst) > 11 || ft_isalpha(lst[0]))
		return (1);
	if (lst[0] != '-' && ft_atoi(lst) < 0)
		return (1);
	if (lst[0] == '-' && i == 0 && lst[1] != '0')
		return (1);
	j = -1;
	while (++j < ft_lstsize(*a))
		if (get_content(*a, j) == i)
			return (1);
	return (0);
}

static int	handle_string(t_list **a, char **av, int i)
{
	int		j;
	char	**lst;
	int		*tmp;
	int		cancel;

	cancel = 0;
	lst = ft_split(av[i], ' ');
	j = 0;
	while (lst[j])
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(lst[j]);
		if (test_val(*tmp, lst[j], a))
			cancel++;
		ft_lstadd_back(a, ft_lstnew(tmp, 0));
		free(lst[j]);
		j++;
	}
	free(lst);
	return (cancel);
}

static int	create_pile(int ac, char **av, t_list **a)
{
	int	i;
	int	*tmp;
	int	cancel;

	i = 0;
	cancel = 0;
	while (++i < ac)
	{
		if (ft_strrchr(av[i], ' ') != NULL)
			cancel += handle_string(a, av, i);
		else
		{
			tmp = malloc(sizeof(int));
			*tmp = ft_atoi(av[i]);
			if (test_val(*tmp, av[i], a))
				cancel++;
			ft_lstadd_back(a, ft_lstnew(tmp, 0));
		}
	}
	return (cancel);
}

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
