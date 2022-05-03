/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/03 17:50:44 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static void	create_pile(int ac, char **av, t_list **a)
{
	int	i;
	int	*tmp;

	*a = 0;
	i = 1;
	while (i < ac)
	{
		tmp = (int*)malloc(sizeof(int));
		*tmp = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(tmp));
		i++;
	}
}

static void	print_iter(t_list *lst)
{
	int	*tmp;

	while (lst)
	{
		tmp = lst->content;
		ft_printf("%d\n", *tmp);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	a = (t_list**)malloc(sizeof(void));
	b = (t_list**)malloc(sizeof(void));
	if (argc <= 1)
		return(0);
	create_pile(argc, argv, a);
	print_iter(*a);
	ft_lstclear(a, free);
	free(a);
	free(b);
}
