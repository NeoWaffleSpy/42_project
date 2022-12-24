/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 19:23:10 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/11 16:18:16 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

int	test_val(int i, char *lst, t_list **a)
{
	int	j;

	if (ft_strlen(lst) > 11 || ft_isalpha(lst[0]))
		return (1);
	if (lst[0] != '-' && ft_atoi(lst) < 0)
		return (1);
	if (lst[0] == '-' && i == 0 && lst[1] != '0')
		return (1);
	j = -1;
	while (++j < (int)ft_strlen(lst))
		if (!ft_isdigit(lst[j]) && (j != 0 || (lst[j] != '-' && lst[j] != '+')))
			return (1);
	j = -1;
	while (++j < ft_lstsize(*a))
		if (get_content(*a, j) == i)
			return (1);
	return (0);
}

int	handle_string(t_list **a, char **av, int i)
{
	int		j;
	char	**lst;
	int		*tmp;
	int		cancel;

	cancel = 0;
	lst = ft_split(av[i], ' ');
	j = 0;
	if (!lst[j])
		cancel++;
	while (lst[j])
	{
		tmp = malloc(sizeof(int));
		*tmp = ft_atoi(lst[j]);
		if (test_val(*tmp, lst[j], a))
			cancel++;
		ft_lstadd_back(a, ft_lstnew(tmp, 0));
		free(lst[j]);
		j++;
	}
	free(lst);
	return (cancel);
}

int	create_pile(int ac, char **av, t_list **a)
{
	int	i;
	int	*tmp;
	int	cancel;

	i = 0;
	cancel = 0;
	while (++i < ac)
	{
		if (ft_strrchr(av[i], ' ') != NULL)
			cancel += handle_string(a, av, i);
		else
		{
			tmp = malloc(sizeof(int));
			*tmp = ft_atoi(av[i]);
			if (test_val(*tmp, av[i], a) || *(av[i]) == '\0')
				cancel++;
			ft_lstadd_back(a, ft_lstnew(tmp, 0));
		}
	}
	return (cancel);
}
