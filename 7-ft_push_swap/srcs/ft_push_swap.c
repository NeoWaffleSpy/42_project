/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:23:38 by ncaba             #+#    #+#             */
/*   Updated: 2022/04/26 15:58:32 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

static t_list	**create_pile(int ac, char **av)
{
	t_list	**a;
	int	i;
	int	*tmp;

	a = (t_list**)malloc(sizeof(void));
	i = 2;
	tmp = (int*)malloc(sizeof(int));
	*tmp = ft_atoi(av[1]);
	*a = ft_lstnew(tmp);
	while (i < ac)
	{
		tmp = (int*)malloc(sizeof(int));
		*tmp = ft_atoi(av[i]);
		ft_lstadd_back(a, ft_lstnew(tmp));
		i++;
	}
	return (a);
}

static void	print_iter(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int*)lst->content);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;

	b = (t_list**)malloc(sizeof(void));
	if (argc <= 1)
		return(0);
	a = create_pile(argc, argv);
	print_iter(*a);
	ft_lstclear(a, free);
	free(a);
	free(b);
}
