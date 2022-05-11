/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/11 23:08:51 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	rra(t_list **a, t_list **b)
{
	t_list	*tmp;

	(void)b;
	if (ft_lstsize(*a) < 1)
		call_error("Invalid operation:", "RRA on empty list A");
	if (ft_lstsize(*a) == 1)
		call_error("Invalid operation:", "RRA on single member list A");
	tmp = get_chain(*a, ft_lstsize(*a)-1);
	ft_lstadd_front(a, ft_lstnew(tmp->content));
	get_chain(*a, ft_lstsize(*a)-2)->next = 0;
	free(tmp);
	ft_printf("rra\n");
}

void	rrb(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
}

void	rrr(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
}
