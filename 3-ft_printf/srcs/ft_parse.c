/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:56:09 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/17 20:34:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	init_flags(t_flags *fl)
{
	fl->is_alternative = FALSE;
	fl->is_padded_zero = FALSE;
	fl->is_padded_left = FALSE;
	fl->is_single_space = FALSE;
	fl->is_plus = FALSE;
	fl->nb_spaces = 0;
	fl->nb_dec = -1;
}

static char	*return_percent()
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (1 + 1));
	str[0] = '%';
	str[1] = '\0';
	return (str);
}

char		*ft_parse(char **str, va_list params)
{
	t_flags	flags;
	int		result;
	char	*str_result;

	init_flags(&flags);
	result = ft_grab_type(str, &flags, params);
	if (result == -1)
	{
		(*str)++;
		str_result = return_percent();
		return (str_result);
	}
	else
		str_result = brancher(result, flags, params);
	/*
	printf("Recognized data type: %d\n", result);
	printf("Recognized data value: %s\n", str_result);
	printf("Flags structure\n");
	printf("| flags->is_alternative = %d\n", flags.is_alternative);
	printf("| flags->is_padded_zero = %d\n", flags.is_padded_zero);
	printf("| flags->is_padded_left = %d\n", flags.is_padded_left);
	printf("| flags->is_single_space = %d\n", flags.is_single_space);
	printf("| flags->is_plus = %d\n", flags.is_plus);
	printf("| flags->nb_spaces = %d\n", flags.nb_spaces);
	printf("| flags->nb_dec = %d\n", flags.nb_dec);
	printf("------------------------------\n");*/
	return (str_result);
}
