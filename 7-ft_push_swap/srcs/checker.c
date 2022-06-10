/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:14:22 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/10 19:14:25 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void static  compute_operations(t_list **a, t_list **b)
{
    char    *operation;

    while (get_next_line(0, &operation))
    {
        if (!ft_strcmp(operation, "sa"))
            sa(a, b, 0);
        else if (!ft_strcmp(operation, "sb"))
            sb(a, b, 0);
        else if (!ft_strcmp(operation, "ss"))
            ss(a, b, 0);
        else if (!ft_strcmp(operation, "pa"))
            pa(a, b, 0);
        else if (!ft_strcmp(operation, "pb"))
            pb(a, b, 0);
        else if (!ft_strcmp(operation, "ra"))
            ra(a, b, 0);
        else if (!ft_strcmp(operation, "rb"))
            rb(a, b, 0);
        else if (!ft_strcmp(operation, "rr"))
            rr(a, b, 0);
        else if (!ft_strcmp(operation, "rra"))
            rra(a, b, 0);
        else if (!ft_strcmp(operation, "rrb"))
            rrb(a, b, 0);
        else if (!ft_strcmp(operation, "rrr"))
            rrr(a, b, 0);
        free(operation);
    }
    free(operation);
}

int main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;

	a = malloc(sizeof(int *));
	b = malloc(sizeof(int *));
	*a = 0;
	*b = 0;
	if (create_pile(ac, av, a))
	{
		ft_lstclear(a, free);
		ft_lstclear(b, free);
		free(a);
		free(b);
		call_error("Incorrect value", "");
	}
	if (ft_lstsize(*a))
        compute_operations(a, b);
    if (ft_lstsize(*a) == 0 || check_sorted(a, 0))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
}