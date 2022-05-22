/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:17:16 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/22 18:09:32 by ncaba            ###   ########.fr       */
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
	int	i;
	int	j;

	size = ft_lstsize(*a);
	i = 0;
	while (!check_sorted(a))
	{
		j = -1;
		while (++j < size - 1)
		{
			if (((get_content(*a, 0) >> i) & 1) == 1)
				ra(a, b, 1);
			else
				pb(a, b, 1);
		}
		while (ft_lstsize(*b) > 0)
			pa(a, b, 1);
		i++;
	}
}

static void	set_pos(int *lst_order, int num, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len)
	{
		if (lst_order[i] < num)
		{
			tmp = lst_order[i];
			lst_order[i] = num;
			num = tmp;
		}
		i++;
	}
	lst_order[i] = num;
}

static int	get_offset(int *lst_order, int num, int pos, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("i = %d\n", i);
		if (lst_order[i] == num)
		{
			ft_printf("pass 1 and pos = %d\n", pos);
			if (i == 0 && pos > len / 2 && lst_order[len - 1] < num)
				return (i - pos + len - 1);
			if (i >= pos || (i < len && lst_order[i + 1] != num) || pos - i > len / 2)
			{
				if (len > 2 && i - pos > len / 2)
					return (i - pos - len);
				else if (len > 2 && i - pos < len / 2 * -1)
					return (i - pos + len);
				else
					return (i - pos);
			}
			ft_printf("...or not\n");
		}
		i++;
	}
	call_error("WTF", "get_offset");
	return (0);
}

void	sort_big_new(t_list **a, t_list **b)
{
	int	*lst_order;
	int	len;
	int	pos;
	int offset;

	pos = 0;
	len = ft_lstsize(*a);
	lst_order = malloc(sizeof(int) * (len + 1));
	lst_order[0] = get_content(*a, 0);
	print_iter(*a);
	print_iter(*b);
	pb(a, b, 1);
	while (ft_lstsize(*a) > 0)
	{
		pos = pos % (len - (ft_lstsize(*a)));
		set_pos(lst_order, get_content(*a, 0), len - ft_lstsize(*a));
		offset = get_offset(lst_order, get_content(*a, 0),
			pos, len - ft_lstsize(*a) + 1);
		while ((offset > 0 || offset < -1) && ft_lstsize(*b) >= 2)
		{
			if (offset < 0)
			{
				rrb(a, b, 1);
				offset++;
				pos--;
			}
			else if (offset > 0)
			{
				rb(a, b, 1);
				offset--;
				pos++;
			}
		}
		if (pos == ft_lstsize(*b))
			pos++;
		pb(a, b, 1);
		if (offset == -1)
			pos--;
		if (ft_lstsize(*b) == 2 && offset != 0)
			sb(a, b, 1);
		print_iter(*a);
		print_iter(*b);
	}
	pos = pos % (len - (ft_lstsize(*a)));
	while (pos > len / 2 && pos < len)
	{
		pos++;
		rb(a, b, 1);
	}
	while (pos < len / 2 && pos > 0)
	{
		pos--;
		rrb(a, b, 1);
	}
	while (ft_lstsize(*b) > 0)
		pa(a, b, 1);
	free(lst_order);
	print_iter(*a);
	print_iter(*b);
}
