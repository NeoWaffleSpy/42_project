/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:48:38 by ncaba             #+#    #+#             */
/*   Updated: 2020/12/17 17:19:37 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define STRING		1
# define U_INT		2
# define INT		3
# define HEX_UP		4
# define HEX_LOW	5
# define CHAR		6
# define PERCENT	7
# define POINTER	8

typedef struct	s_flags
{
	boolean		is_alternative;      //Modifie les flags "oxXaAeEfFgG"
	boolean		is_padded_zero;      //Ajoute nb_space-size '0' a gauche
	boolean		is_padded_left;      //Justifie la string a gauche
	boolean		is_single_space;     //Ajoute un espace unique a gauche
	boolean		is_plus;             //si entier signé positif, on rajoute un +
	int			nb_spaces;           //Ajoute des espaces justifiable
	int			nb_dec;              //Définis le nombre max de decimale
}				t_flags;

int				ft_printf(char *str, ...);
int				ft_grab_type(char **str, t_flags *flags, va_list params);
char			*ft_parse(char **str, va_list params);
char			*ft_itoa_base(long long n, char *base);
void			ft_decimal_check(char *str, t_flags *flags, 
								int *loop, va_list params);
void			ft_spacing_check(char *str, t_flags *params, int *loop);
void			ft_add_padd(char **str, t_flags flags, int type);
void			ft_add_space(char **str, t_flags flags, int type);
void			ft_add_precis(char **str, t_flags flags);
void			ft_alternative(char **str, t_flags flags, int type);
char			*brancher(int type, t_flags flags, va_list params);
char			*ft_convert_string(t_flags flags, va_list params);
char			*ft_convert_pointer(t_flags flags, va_list params);
char			*ft_convert_int(t_flags flags, va_list params);
char			*ft_convert_hexa(t_flags flags, va_list params, boolean is_up);
char			*ft_convert_char(t_flags flags, va_list params);
char			*ft_convert_percent();
char			*ft_convert_unsigned(t_flags flags, va_list params);

#endif
