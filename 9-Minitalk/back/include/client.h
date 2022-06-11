/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:01:00 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/09 19:01:05 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../include/libft/include/ft_lib.h"
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>

# define DELAY_US 20000

struct		s_args
{
	int		pid;
	char	*str;
};

#endif
