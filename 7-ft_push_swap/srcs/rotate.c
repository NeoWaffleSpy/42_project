/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:34 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/26 16:31:56 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	ra(t_list **a, t_list **b, int dual)
{
	t_list	*tmp;

	(void)b;
	if (ft_lstsize(*a) < 1)
		call_error("Invalid operation:", "RA on empty list A");
	if (ft_lstsize(*a) == 1)
		return;
	tmp = get_chain(*a, 1);
	ft_lstadd_back(a, ft_lstnew((*a)->content));
	(*a)->content = tmp->content;
	(*a)->next = tmp->next;
	free(tmp);
	if (dual)
		ft_printf("ra\n");
}

void	rb(t_list **a, t_list **b, int dual)
{
	t_list	*tmp;

	(void)a;
	if (ft_lstsize(*b) < 1)
		call_error("Invalid operation:", "RB on empty list B");
	if (ft_lstsize(*b) == 1)
		return;
	tmp = get_chain(*b, 1);
	ft_lstadd_back(b, ft_lstnew((*b)->content));
	(*b)->content = tmp->content;
	(*b)->next = tmp->next;
	free(tmp);
	if (dual)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b, int dual)
{
	(void)dual;
	ra(a, b, 0);
	rb(a, b, 0);
	ft_printf("rr\n");
}
