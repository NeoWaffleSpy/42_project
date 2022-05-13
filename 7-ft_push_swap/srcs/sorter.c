/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:17:16 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/13 07:23:12 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	check_sorted(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp_next;
	int	*val1;
	int	*val2;

	tmp = *a;
	while (tmp->next)
	{
		tmp_next = tmp->next;
		val1 = tmp->content;
		val2 = tmp_next->content;
		if (*val1 > *val2)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3(t_list **a, t_list **b)
{
	int	f_val;
	int	s_val;
	int	t_val;

	(void)b;
	f_val = get_content(*a, 0);
	s_val = get_content(*a, 1);
	t_val = get_content(*a, 2);
	if (f_val > s_val && s_val < t_val && f_val < t_val)
		sa(a, b, 1);
	if (f_val > s_val && s_val < t_val && f_val > t_val)
		ra(a, b, 1);
	if (f_val < s_val && s_val > t_val && f_val > t_val)
		rra(a, b, 1);
	else if (f_val > s_val && s_val > t_val)
	{
		sa(a, b, 1);
		rra(a, b, 1);
	}
	else if ((f_val < s_val && s_val > t_val && f_val < t_val))
	{
		sa(a, b, 1);
		ra(a, b, 1);
	}
}

void	sort_4_5(t_list **a, t_list **b, int median)
{
	int	count;

	count = 0;
	while (count < median)
	{
		if (get_content(*a, 0) < median)
		{
			pb(a, b, 1);
			count++;
		}
		else
			ra(a, b, 1);
	}
	sort_3(a, b);
	if (median > 1)
	{
		if (get_content(*b, 0) < get_content(*b, 1))
			sb(a, b, 1);
		pa(a, b, 1);
	}
	pa(a, b, 1);
}

void	sort_big(t_list **a, t_list **b)
{
	int	size;
	int	max_bit;
	int	i;
	int	j;

	size = ft_lstsize(*a);
	max_bit = 0;
	while ((size - 1) >> max_bit != 0)
		max_bit++;
	i = -1;
	while (++i < max_bit)
	{
		j = -1;
		while (++j < size)
		{
			if (((get_content(*a, 0) >> i) & 1) == 1)
				ra(a, b, 1);
			else
				pb(a, b, 1);
		}
		print_iter(*a);
		print_iter(*b);
		while (ft_lstsize(*b) > 0)
			pa(a, b, 1);
		print_iter(*a);
		print_iter(*b);
	}
}
