/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:43:15 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/09 18:43:19 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static void	display_pid(void)
{
	pid_t	pid;
	char	*str_pid;

	pid = getpid();
	str_pid = ft_itoa(pid);
	if (!str_pid)
	{
		ft_printf_fd(2, "Error at ft_itoa()");
		return ;
	}
	ft_printf("%s\n", str_pid);
	free(str_pid);
}

static void	handler_msg(int sig, siginfo_t *info, void *ucontext)
{
	static struct s_character	chr = {0, 0};

	(void)ucontext;
	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	struct sigaction	sa;

	display_pid();
	sa.sa_handler = SIG_DFL;
	sa.sa_sigaction = handler_msg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
