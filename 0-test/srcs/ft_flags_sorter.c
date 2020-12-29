/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sorter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:31:46 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/29 14:38:16 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	indicateur_flag(char *c, t_flags *fl, int *loop, va_list params)
{
	(void)loop;
	(void)params;
	if (*c == '-')
	{
		fl->is_padded_left = TRUE;
		fl->is_padded_zero = FALSE;
	}
	if (*c == ' ')
		fl->is_single_space = TRUE;
	if (*c == '0')
		if (fl->is_padded_left == FALSE)
			fl->is_padded_zero = TRUE;
	if (*c == '#')
		fl->is_alternative = TRUE;
	if (*c == '+')
		fl->is_plus = TRUE;
	if (ft_strchr("- #+0", *c))
		return (0);
	return (-1);
}

static int	width_flag(char *c, t_flags *fl, int *loop, va_list params)
{
	if (*c == '*')
		ft_spacing_check(c, fl, loop, params);
	if (*c != '0' && ft_isdigit(*c))
		ft_spacing_check(c, fl, loop, params);
	if (ft_strchr("*123456789", *c))
		return (0);
	return (-1);
}

static int	precision_flag(char *c, t_flags *fl, int *loop, va_list params)
{
	if (*c == '.')
	{
		ft_decimal_check(c, fl, loop, params);
		if (fl->nb_dec >= 0)
			fl->is_padded_zero = FALSE;
	}
	if (ft_strchr(".", *c))
		return (0);
	return (-1);
}

static int	sort_letters(char c)
{
	if (c == 'u')
		return (U_INT);
	if (c == 's')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'd' || c == 'i')
		return (INT);
	if (c == 'x')
		return (HEX_LOW);
	if (c == 'X')
		return (HEX_UP);
	if (c == 'c')
		return (CHAR);
	if (c == '%')
		return (PERCENT);
	return (0);
}

int			ft_grab_type(char **str, t_flags *flags, va_list params)
{
	int		loop;
	int		type;
	int		fc;
	int		(*(*p))(char*, t_flags*, int*, va_list);

	p = malloc(sizeof(void*) * 3);
	p[0] = indicateur_flag;
	p[1] = width_flag;
	p[2] = precision_flag;
	fc = 0;
	loop = 1;
	type = 0;
	while (type == 0)
	{
		type = sort_letters((*str)[loop]);
		if (type == 0)
			while ((type = p[fc++](&((*str)[loop]), flags, &loop, params)) < 0)
				if (fc >= 3)
					return (-1);
		loop++;
		fc--;
	}
	free(p);
	*str += loop;
	return (type);
}
