/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:00 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/14 19:48:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../include/libft/include/ft_lib.h"
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>

# define DELAY_US 0

struct		s_args
{
	int		pid;
	char	*str;
	int		character;
	int		current_bit;
};

#endif
