/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:24 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/23 15:24:50 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	boot_philo(t_rules *rules)
{
	int	i;
	int	time;
	pthread_t	tid;

	i = 0;
	time = get_time();
	pthread_mutex_lock(&(rules->die_mutex));
	while (i < rules->nb_philo)
	{
		rules->philosophers[i].last_meal = time + rules->ttdie;
		if (pthread_create(&tid, NULL, &routine, &(rules->philosophers[i])))
			return (call_error("Failed Philosopher boot", ""));
		pthread_detach(tid);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_rules rules;

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
	pthread_mutex_lock(&(rules.die_mutex));
	pthread_mutex_unlock(&(rules.die_mutex));
	free_all(&rules);
}
