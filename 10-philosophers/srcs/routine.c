/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/23 15:46:39 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	set_fork(t_philosopher *philo, int pos, int *fork)
{
	pthread_mutex_lock(&(philo->rules->forks_mutex[pos]));
	if (*fork == pos)
		*fork = 0;
	else if (*fork == 0)
		*fork = pos;
	else
	{
		pthread_mutex_unlock(&(philo->rules->forks_mutex[pos]));
		return(1);
	}
	pthread_mutex_unlock(&(philo->rules->forks_mutex[pos]));
	return (0);
}

static void	thread_print(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("%d %3d %s\n", get_time(), philo->position, str);
	pthread_mutex_unlock(&(philo->rules->print_mutex));
}

static int	kill_philo(t_philosopher *philo)
{
	if (philo->rules->dead == TRUE)
		return (1);
	philo->rules->dead = TRUE;
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("%d %3d %s\n", get_time(), philo->position, "died");
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	return (1);
}

static int	take_fork(t_philosopher *philo)
{
	while (*(philo->r_fork) != philo->position && *(philo->l_fork) != philo->position)
	{
		if (philo->last_meal <= get_time() || philo->rules->dead == TRUE)
			return (kill_philo(philo));
		if (*(philo->r_fork) != philo->position)
			set_fork(philo, philo->position, philo->r_fork);
		if (*(philo->l_fork) != philo->position)
			set_fork(philo, philo->position, philo->l_fork);
	}
	return (0);
}

static int	eat(t_philosopher *philo)
{
	if (philo->last_meal <= get_time() || philo->rules->dead == TRUE)
		return (kill_philo(philo));
	thread_print(philo, "is eating");
	philo->last_meal = get_time() + philo->rules->ttdie;
	philo->meals += 1;
	if (philo->rules->ttdie < philo->rules->tteat)
		usleep(philo->rules->ttdie);
	else
		usleep(philo->rules->tteat);
	set_fork(philo, philo->position, philo->r_fork);
	set_fork(philo, philo->position, philo->l_fork);
	if (philo->meals >= philo->rules->max_iteration)
	{
		pthread_mutex_lock(&(philo->rules->finish_mutex));
		philo->rules->finished++;
		pthread_mutex_unlock(&(philo->rules->finish_mutex));
		if (philo->rules->finished == philo->rules->nb_philo)
			pthread_mutex_unlock(&(philo->rules->die_mutex));
		return (1);
	}
	return (0);
}

static int	sleeping(t_philosopher *philo)
{
	if (philo->last_meal <= get_time() || philo->rules->dead == TRUE)
		return (kill_philo(philo));
	thread_print(philo, "is sleeping");
	if (get_time() + philo->rules->ttsleep >= philo->last_meal)
		usleep(philo->last_meal - get_time());
	else
		usleep(philo->rules->ttsleep);
	thread_print(philo, "is thinking");
	return (0);
}

void	*routine(void *tmp_philo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)tmp_philo;
	while (1)
	{
		if (philo->rules->max_iteration >= 0 &&
				philo->meals >= philo->rules->max_iteration)
			break;
		if (take_fork(philo) || eat(philo) || sleeping(philo))
			break;
	}
	return (NULL);
}
