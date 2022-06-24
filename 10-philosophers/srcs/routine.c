/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/24 15:37:57 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	thread_print(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("%4d |%3d %s\n", get_time(philo->rules), philo->position, str);
	pthread_mutex_unlock(&(philo->rules->print_mutex));
}

static int	set_fork(t_philosopher *philo, int pos, int *fork)
{
	pthread_mutex_lock(&(philo->rules->forks_mutex[pos-1]));
	if (fork == NULL)
	{
		pthread_mutex_unlock(&(philo->rules->forks_mutex[pos-1]));
		return(1);
	}
	else if (*fork == pos)
		*fork = 0;
	else if (*fork == 0)
	{
		*fork = pos;
		thread_print(philo, "took a fork");
	}
	else
	{
		pthread_mutex_unlock(&(philo->rules->forks_mutex[pos-1]));
		return(1);
	}
	pthread_mutex_unlock(&(philo->rules->forks_mutex[pos-1]));
	return (0);
}

static int	kill_philo(t_philosopher *philo)
{
	if (philo->rules->dead == TRUE)
		return (1);
	philo->rules->dead = TRUE;
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("%4d |%3d %s\n", get_time(philo->rules),
		philo->position, "died");
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	return (1);
}

static int	take_fork(t_philosopher *philo)
{
	while (!philo->l_fork || (*(philo->r_fork) != philo->position &&
		*(philo->l_fork) != philo->position))
	{
//		thread_print(philo, "loop");
		if (philo->last_meal <= get_time(philo->rules) ||
			philo->rules->dead == TRUE)
			return (kill_philo(philo));
		if (*(philo->r_fork) != philo->position)
			set_fork(philo, philo->position, philo->r_fork);
		if (philo->l_fork && *(philo->l_fork) != philo->position)
			set_fork(philo, philo->position, philo->l_fork);
//		usleep(1000);
	}
	return (0);
}

static int	eat(t_philosopher *philo)
{
	if (philo->last_meal <= get_time(philo->rules) ||
		philo->rules->dead == TRUE)
		return (kill_philo(philo));
	thread_print(philo, "is eating");
	philo->last_meal = get_time(philo->rules) + philo->rules->ttdie;
	philo->meals += 1;
	if (philo->rules->ttdie < philo->rules->tteat)
		usleep(philo->rules->ttdie * 1000);
	else
		usleep(philo->rules->tteat * 1000);
	set_fork(philo, philo->position, philo->r_fork);
	set_fork(philo, philo->position, philo->l_fork);
	if (philo->meals >= philo->rules->max_iteration)
	{
		pthread_mutex_lock(&(philo->rules->finish_mutex));
		philo->rules->finished++;
		pthread_mutex_unlock(&(philo->rules->finish_mutex));
		thread_print(philo, "has finished his meals");
		printf("--------------> %d philo have finished\n", philo->rules->finished);
		if (philo->rules->finished == philo->rules->nb_philo)
			pthread_mutex_unlock(&(philo->rules->die_mutex));
		return (1);
	}
	return (0);
}

static int	sleeping(t_philosopher *philo)
{
	if (philo->last_meal <= get_time(philo->rules) ||
		philo->rules->dead == TRUE)
		return (kill_philo(philo));
	thread_print(philo, "is sleeping");
	if (get_time(philo->rules) + philo->rules->ttsleep >= philo->last_meal)
		usleep((philo->last_meal - get_time(philo->rules)) * 1000);
	else
		usleep(philo->rules->ttsleep * 1000);
	thread_print(philo, "is thinking");
	return (0);
}

void	*routine(void *tmp_philo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)tmp_philo;
//	printf("time is: %d - ttdie: %d\n", get_time(philo->rules), philo->last_meal);
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
