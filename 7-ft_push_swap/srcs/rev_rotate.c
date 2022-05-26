/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/26 16:32:05 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	rra(t_list **a, t_list **b, int dual)
{
	t_list	*tmp;

	(void)b;
	if (ft_lstsize(*a) < 1)
		call_error("Invalid operation:", "RRA on empty list A");
	if (ft_lstsize(*a) == 1)
		return;
	tmp = get_chain(*a, ft_lstsize(*a)-1);
	ft_lstadd_front(a, ft_lstnew(tmp->content));
	get_chain(*a, ft_lstsize(*a)-2)->next = 0;
	free(tmp);
	if (dual)
		ft_printf("rra\n");
}

void	rrb(t_list **a, t_list **b, int dual)
{
	t_list	*tmp;

	(void)a;
	if (ft_lstsize(*b) < 1)
		call_error("Invalid operation:", "RRB on empty list B");
	if (ft_lstsize(*b) == 1)
		return;
	tmp = get_chain(*b, ft_lstsize(*b)-1);
	ft_lstadd_front(b, ft_lstnew(tmp->content));
	get_chain(*b, ft_lstsize(*b)-2)->next = 0;
	free(tmp);
	if (dual)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b, int dual)
{
	(void)dual;
	rra(a, b, 0);
	rrb(a, b, 0);
	ft_printf("rrr\n");
}
