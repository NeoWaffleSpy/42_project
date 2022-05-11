/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:17:16 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/11 23:29:18 by ncaba            ###   ########.fr       */
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
