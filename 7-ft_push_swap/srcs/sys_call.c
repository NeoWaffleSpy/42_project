/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/06 20:04:18 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	call_error(char *error, char *value)
{
	ft_printf_fd(2, "%s[%sError%s]: ", WHITE, RED, WHITE);
	ft_printf_fd(2, "%s %s%s%s\n", error, YELLOW, value, WHITE);
	exit(1);
}

void	call_info(char *info, char *value)
{
	ft_printf("%s[%sInfo%s]: ", WHITE, GREEN, WHITE);
	ft_printf("%-20s %s%s%s\n", info, CYAN, value, WHITE);
}

void	print_iter(t_list *lst)
{
	int	*tmp;
	int	i;

	i = 0;
	if (ft_lstsize(lst) < 1)
	{
		call_info("empty list", "");
		return ;
	}
	while (lst)
	{
		tmp = lst->content;
		ft_printf("-%3d", *tmp);
		lst = lst->next;
		i++;
	}
	ft_printf("\n", *tmp);
}
