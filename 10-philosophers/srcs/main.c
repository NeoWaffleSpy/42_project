/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:24 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/22 19:00:25 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	start(t_main *rules)
{
	int i;
	pthread_t   tid;

	i = 0;
	pthread_mutex_lock(&(rules->die_mutex));
	while (i < rules->nb_philo)
	{
		if (pthread_create(&tid, NULL, &routine, &(rules->philosophers[i])))
			return (call_error("Failed Philosopher boot", ""));
		pthread_detach(tid);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    t_rules rules;

    if (set_rules(ac, av, &rules) || init_philo(&rules) || init_mutex(&rules))
        return (1);
    if (boot_philo(&rules))
        return (1);
    pthread_mutex_lock(rules.die_mutex);
    pthread_mutex_unlock(rules.die_mutex);
    free_all(&rules);
}