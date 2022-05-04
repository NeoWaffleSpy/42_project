/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:23:22 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/04 18:03:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	pa(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_lstadd_front(b, ft_lstnew((*a)->content));
	if (ft_lstsize(*a) > 1)
	{
		free((*a)->content);
		tmp = get_chain(*a, 1);
		(*a)->content = tmp->content;
		(*a)->next = tmp->next;
		free(tmp);
	}
	else
		ft_lstdelone(*a, free);
	ft_printf("pb\n");
}
