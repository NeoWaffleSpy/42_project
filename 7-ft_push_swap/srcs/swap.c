/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:22:32 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/04 02:15:28 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

t_list	*get_chain(t_list *list, int place)
{
	int		i;
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

int	get_content(t_list *list, int place)
{
	int	*tmp;

	tmp = get_chain(list, place)->content;
	return (*tmp);
}

void	sa(t_list **a, t_list **b, int dual)
{
	t_list	*tmp_list;
	int		*tmp_val;
	int		tmp_index;

	if (ft_lstsize(*a) < 2)
		call_error("Called function on invalid list", "SA");
	(void)b;
	tmp_list = get_chain(*a, 1);
	tmp_val = tmp_list->content;
	tmp_list->content = (*a)->content;
	(*a)->content = tmp_val;
	tmp_index = tmp_list->index;
	tmp_list->index = (*a)->index;
	(*a)->index = tmp_index;
	if (dual)
		ft_printf("sa\n");
}

void	sb(t_list **a, t_list **b, int dual)
{
	t_list	*tmp;
	int		*tmp_val;
	int		tmp_index;

	if (ft_lstsize(*b) < 2)
		call_error("Called function on invalid list", "SB");
	(void)a;
	tmp = (*b)->next;
	tmp_val = tmp->content;
	tmp->content = (*b)->content;
	(*b)->content = tmp_val;
	tmp_index = tmp->index;
	tmp->index = (*b)->index;
	(*b)->index = tmp_index;
	if (dual)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b, int dual)
{
	(void)dual;
	sa(a, b, 0);
	sb(a, b, 0);
	if (dual)
		ft_printf("ss\n");
}
