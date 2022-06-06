/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:17:16 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/06 20:26:43 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void static	set_new_pos(int *lst_order, int num, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len)
	{
		if (lst_order[i] > num)
		{
			tmp = lst_order[i];
			lst_order[i] = num;
			num = tmp;
		}
		i++;
	}
	lst_order[i] = num;
}

void static	write_index(t_list **list, int place, int index)
{
	t_list	*tmp;

	tmp = get_chain(*list, place);
	tmp->index = index;
}

void static	set_index(t_list **a)
{
	int	*lst_order;
	int	len;
	int	i;
	int	j;

	i = -1;
	len = ft_lstsize(*a);
	lst_order = malloc(sizeof(int) * (len + 1));
	while (++i < len)
		set_new_pos(lst_order, get_content(*a, i), i);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			if (get_content(*a, i) == lst_order[j])
				write_index(a, i, j);
	}
	free(lst_order);
}

void	sort_big_index(t_list **a, t_list **b)
{
	int	size;
	int	i;
	int	j;

	set_index(a);
	size = ft_lstsize(*a);
	i = 0;
	while (i < 10 && !check_sorted(a, 0))
	{
//		print_iter(*a);
		j = -1;
		while (++j < size)
		{
			if (((get_chain(*a, 0)->index >> i) & 1) == 1)
				ra(a, b, 1);
			else
				pb(a, b, 1);
		}
		while (ft_lstsize(*b) > 0)
			pa(a, b, 1);
		i++;
	}
}
