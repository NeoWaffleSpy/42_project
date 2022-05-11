/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:22 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/11 21:40:16 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*b) < 1)
		call_error("Invalid operation:", "PA on empty list B");
	ft_lstadd_front(a, ft_lstnew((*b)->content));
	if (ft_lstsize(*b) > 1)
	{
		tmp = get_chain(*b, 1);
		(*b)->content = tmp->content;
		(*b)->next = tmp->next;
		free(tmp);
	}
	else
		ft_lstdelone(*b, free);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*a) < 1)
		call_error("Invalid operation:", "PB on empty list A");
	ft_lstadd_front(b, ft_lstnew((*a)->content));
	if (ft_lstsize(*a) > 1)
	{
		tmp = get_chain(*a, 1);
		(*a)->content = tmp->content;
		(*a)->next = tmp->next;
		free(tmp);
	}
	else
		ft_lstdelone(*a, free);
	ft_printf("pb\n");
}
