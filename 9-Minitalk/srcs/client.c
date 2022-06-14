/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:42:57 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/14 19:48:49 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

static void	send_char(int pid, char character, int current_bit)
{
	if (character & (1 << current_bit))
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(DELAY_US);
	current_bit++;
}

static void	send_message(struct s_args *args)
{
	static struct s_args	*arg;

	if (args)
	{
		arg = args;
		arg->character = 0;
		arg->current_bit = 0;
	}
	else
	{
		arg->current_bit++;
		if (arg->current_bit >= 8)
		{
			arg->current_bit = 0;
			arg->character++;
		}
	}
	if (arg->character >= (int)ft_strlen(arg->str))
		return;
//	ft_printf("writing char %d (%c), bit %d\n", arg->character, arg->str[arg->character], arg->current_bit);
	send_char(arg->pid, arg->str[arg->character], arg->current_bit);
}

static bool	is_natural(const char *str)
{
	size_t	i;
	bool	not_empty;

	not_empty = false;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			not_empty = true;
		else
			return (false);
		i++;
	}
	return (not_empty);
}

static void	acknowledgment_handler(int sig)
{
	(void)sig;
	send_message(NULL);
}

static bool	parse_args(struct s_args *args, int argc, char *argv[])
{
	if (!args || argc != 3 || !is_natural(argv[1]))
		return (false);
	args->pid = ft_atoi(argv[1]);
	args->str = argv[2];
	return (true);
}

int	main(int argc, char *argv[])
{
	struct s_args	args;

	signal(SIGUSR1, acknowledgment_handler);
	if (!parse_args(&args, argc, argv))
	{
		ft_printf_fd(2, "%s[%sError%s] %sUsage: %s%s <server_pid> \"<string>\"\n",
			WHITE, RED, WHITE, YELLOW, GREEN, argv[0]);
		return (1);
	}
	send_message(&args);
	return (0);
}
