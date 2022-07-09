/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:24 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/09 22:36:23 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	boot_philo(t_rules *rules)
{
	int			i;

	i = 0;
	rules->start_time = get_time(rules);
	while (i < rules->nb_philo)
	{
		if (pthread_create(&(rules->philosophers[i].thread),
				NULL, &routine, &(rules->philosophers[i])))
			return (call_error("Failed Philosopher boot", ""));
		i++;
	}
	return (0);
}

static void	join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philosophers[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (set_rules(ac, av, &rules) || init_philo(&rules))
		return (1);
	if (init_mutex(&rules))
	{
		free_malloc(&rules);
		return (1);
	}
	if (boot_philo(&rules))
	{
		free_all(&rules);
		return (1);
	}
	while (1)
	{
		pthread_mutex_lock(&(rules.finish_mutex));
		if (rules.finished == rules.nb_philo)
			break ;
		pthread_mutex_unlock(&(rules.finish_mutex));
		usleep(100);
	}
	pthread_mutex_unlock(&(rules.finish_mutex));
	join_threads(&rules);
	free_all(&rules);
}
