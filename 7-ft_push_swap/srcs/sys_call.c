/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/05/04 16:02:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_push_swap.h"

void	call_error(char *error, char *value)
{
	ft_printf("%s[%sError%s]: ", WHITE, RED, WHITE);
	ft_printf("%s %s%s%s\n", error, YELLOW, value, WHITE);
	exit(1);
}

void	call_info(char *info, char *value)
{
	ft_printf("%s[%sInfo%s]: ", WHITE, GREEN, WHITE);
	ft_printf("%-20s %s%s%s\n", info, CYAN, value, WHITE);
}
