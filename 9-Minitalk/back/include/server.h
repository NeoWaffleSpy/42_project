/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:13 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/09 19:01:14 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../include/libft/include/ft_lib.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

struct		s_character
{
	char	character;
	int		current_bit;
};

#endif
