/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:17:16 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/26 18:25:16 by ncaba            ###   ########.fr       */
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

int	ft_pow(int operator, int operand)
{
	int	res;

	if (operand == 0)
		return (1);
	if (operand > 0)
	{
		res = operator;
		while (--operand > 0)
			res *= operator;
	}
	if (operand < 0)
	{
		res = 1;
		while (operand++ < 0)
			res /= operator;
	}
	return (res);
}

int	check_exist(t_list *a, int num, int k)
{
	t_list *tmp;
	int	*val;

	tmp = a;
	while (tmp != NULL)
	{
		val = tmp->content;
		if (((*val / ft_pow(10, k)) % 10) == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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
	while (i < 10)
	{
		print_iter(*a);
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

void	sort_big_2(t_list **a, t_list **b)
{
	int	size;
	int	i;
	int	j;
	int	k;

	k = 0;
	while (!check_sorted(a) && k < 10)
	{
		i = -10;
		while (++i < 10)
		{
			size = ft_lstsize(*a);
			if (!check_exist(*a, i, k))
				continue;
			j = -1;
			while (++j < size)
			{
				if (((get_content(*a, 0) / ft_pow(10, k)) % 10) != i)
					ra(a, b, 1);
				else
					pb(a, b, 1);
			}
		}
		while (ft_lstsize(*b) > 0)
			pa(a, b, 1);
		k++;
	}
}

void	sort_big_3_1(t_list **a, t_list **b, int k)
{
	int	size;
	int	i;
	int	j;

	i = -10;
	while (++i < 10)
	{
		size = ft_lstsize(*a);
		if (!check_exist(*a, i, k))
			continue;
		j = -1;
		while (++j < size)
		{
			if (((get_content(*a, 0) / ft_pow(10, k)) % 10) != i)
				ra(a, b, 1);
			else
				pb(a, b, 1);
		}
	}
	sort_big_3_2(b, a, k + 1);
}

void	sort_big_3_2(t_list **a, t_list **b, int k)
{
	int	size;
	int	i;
	int	j;

	i = 10;
	while (--i > -10)
	{
		size = ft_lstsize(*a);
		if (!check_exist(*a, i, k))
			continue;
		j = -1;
		while (++j < size)
		{
			if (((get_content(*a, 0) / ft_pow(10, k)) % 10) != i)
				ra(a, b, 1);
			else
				pb(a, b, 1);
		}
	}
	if (!check_sorted(b))
		sort_big_3_1(b, a, k + 1);
}


static void	set_pos(int *lst_order, int num, int len, int *pos)
{
	int	i;
	int	check;
	int	tmp;

	i = 0;
	check = 1;
	while (i < len)
	{
		if (lst_order[i] < num)
		{
			if (check && *pos >= i)
			{
				*pos += 1;
				check = 0;
			}
			tmp = lst_order[i];
			lst_order[i] = num;
			num = tmp;
		}
		i++;
	}
	lst_order[i] = num;
}

static void	print_lst(int *lst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("-%d", lst[i]);
		i++;
	}
	ft_printf("\n");
}

static int	get_offset(int *lst_order, int num, int pos, int len)
{
	int	i;
	int	posi;
	int	neg;

	i = 0;
	while (i <= len / 2)
	{
		posi = (pos + i) % len;
		neg = (pos - i);
		if (neg < 0)
			neg += len;
		if (lst_order[posi] == num)
			return (i);
		if (lst_order[neg] == num)
			return (-i);
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
	int	offset;

	(void)print_lst;
	pos = 0;
	len = ft_lstsize(*a);
	lst_order = malloc(sizeof(int) * (len + 1));
	lst_order[0] = get_content(*a, 0);
	pb(a, b, 1);
	while (ft_lstsize(*a) > 0)
	{
		pos = pos % (len - (ft_lstsize(*a)));
		if (pos < 0)
			pos += len - (ft_lstsize(*a));
		set_pos(lst_order, get_content(*a, 0), len - ft_lstsize(*a), &pos);
		offset = get_offset(lst_order, get_content(*a, 0),
			pos, len - ft_lstsize(*a) + 1);
		while ((offset > 0 || offset < -1) && ft_lstsize(*b) >= 2)
		{
			if (offset < -1)
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
		if (pos == ft_lstsize(*b) && offset != -1)
			pos++;
		pb(a, b, 1);
		if (offset == -1)
			pos--;
		if (ft_lstsize(*b) == 2 && offset != 0)
			sb(a, b, 1);
	}
	pos = pos % (len + 1);
	if (pos < 0)
		pos += (len + 1);
	while (pos > len / 2 && pos <= len)
	{
		pos++;
		rb(a, b, 1);
	}
	while (pos <= len / 2 && pos > 0)
	{
		pos--;
		rrb(a, b, 1);
	}
	while (ft_lstsize(*b) > 0)
		pa(a, b, 1);
	free(lst_order);
//	print_iter(*a);
//	print_iter(*b);
}
