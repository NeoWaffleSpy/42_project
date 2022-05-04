/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:22:32 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/04 17:38:59 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_list	*get_chain(t_list *list, int place)
{
	int i;
	t_list	*iter;

	i = 0;
	iter = list;
	if (!iter)
		call_error("Empty List", "get_chain");
	while (iter && i < place)
	{
		iter = iter->next;
		i++;
	}
	return (iter);
}

void	sa(t_list **a, t_list **b)
{
	t_list	*tmp_list;
	int	*tmp_val;

	if (ft_lstsize(*a) < 2)
		call_error("Called function on invalid list", "SA");
	(void)b;
	tmp_list = get_chain(*a, 1);
	tmp_val = tmp_list->content;
	tmp_list->content = (*a)->content;
	(*a)->content = tmp_val;
	ft_printf("sa\n");
}

void	sb(t_list **a, t_list **b)
{
	t_list *tmp;
	int	*tmp_val;

	if (ft_lstsize(*b) < 2)
		call_error("Called function on invalid list", "SB");
	(void)a;
	tmp = (*b)->next;
	tmp_val = tmp->content;
	tmp->content = (*b)->content;
	(*b)->content = tmp_val;
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, b);
	sb(a, b);
}
