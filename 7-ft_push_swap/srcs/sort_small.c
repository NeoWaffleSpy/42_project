/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:25:01 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/06 21:53:20 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	check_sorted(t_list **a, int rev)
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
		if (rev == 0 && *val1 > *val2)
			return (0);
		else if (rev == 1 && *val1 < *val2)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3(t_list **a, t_list **b)
{
	int	val[3];

	(void)b;
	val[0] = get_content(*a, 0);
	val[1]  = get_content(*a, 1);
	val[2]  = get_content(*a, 2);
	if (val[0] > val[1] && val[1] < val[2] && val[0] < val[2])
		sa(a, b, 1);
	if (val[0] > val[1] && val[1] < val[2] && val[0] > val[2])
		ra(a, b, 1);
	if (val[0] < val[1] && val[1] > val[2] && val[0] > val[2])
		rra(a, b, 1);
	else if (val[0] > val[1] && val[1] > val[2])
	{
		sa(a, b, 1);
		rra(a, b, 1);
	}
	else if ((val[0] < val[1] && val[1] > val[2] && val[0] < val[2]))
	{
		sa(a, b, 1);
		ra(a, b, 1);
	}
	while (!check_sorted(a, 0))
		ra(a, b, 1);
}

void static	get_smallest(t_list **a, t_list **b)
{
	int	small;
	int	i;

	i = 0;
	small = 0;
	while (++i < ft_lstsize(*a))
		if (get_content(*a, small) > get_content(*a, i))
			small = i;
	if (small > ft_lstsize(*a) / 2)
		small -= ft_lstsize(*a);
	while (small != 0)
	{
		if (small < 0)
		{
			rra(a, b, 1);
			small++;
		}
		else if (b > 0)
		{
			ra(a, b, 1);
			small--;
		}
	}
	pb(a, b, 1);
}

void	sort_4_5(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		get_smallest(a, b);
	sort_3(a, b);
	pa(a, b, 1);
	pa(a, b, 1);
}
