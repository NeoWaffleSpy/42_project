/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/01 17:39:48 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	ft_sleep(int time, t_philosopher *philo)
{
	int	finish;

	finish = get_time(philo->rules) + time;
	while (get_time(philo->rules) < finish)
		usleep(10);
}

static int	thread_print(t_philosopher *philo, char *str)
{
//	if (philo->position != 1)
//		return;
	pthread_mutex_lock(&(philo->rules->print_mutex));
	if (philo->rules->dead)
		return (1);
	printf("| %3d | %3d %s\n", get_time(philo->rules), philo->position, str);
//	ft_printf(get_time(philo->rules), philo->position, str);
	pthread_mutex_unlock(&(philo->rules->print_mutex));
	return (0);
}

static int	set_fork(t_philosopher *philo, int pos, int *fork)
{
	if (fork == NULL)
		return(1);
	else if (*fork == pos)
		*fork = 0;
	else if (*fork == 0)
	{
		*fork = pos;
		if (thread_print(philo, "took a fork"))
			return (1);
	}
	else
		return(1);
	return (0);
}

static int	kill_philo(t_philosopher *philo)
{
	if (philo->rules->dead == TRUE)
		return (1);
	philo->rules->dead = TRUE;
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("| %3d | %3d %s\n", get_time(philo->rules), philo->position, "died");
//	ft_printf(get_time(philo->rules), philo->position, "died");
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	return (1);
}

static int	take_fork(t_philosopher *philo)
{
	int	looped;

	if (philo->position == philo->rules->nb_philo)
		looped = 0;
	else
		looped = philo->position;
	while (!philo->l_fork || *(philo->r_fork) != philo->position ||
		*(philo->l_fork) != philo->position)
	{
		usleep(5);
		if (philo->last_meal <= get_time(philo->rules) ||
			philo->rules->dead == TRUE)
			return (kill_philo(philo));
		pthread_mutex_lock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (*(philo->r_fork) != philo->position)
			set_fork(philo, philo->position, philo->r_fork);
		pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (!philo->l_fork)
			continue;
		pthread_mutex_lock(&(philo->rules->forks_mutex[looped]));
		if (*(philo->l_fork) != philo->position)
			set_fork(philo, philo->position, philo->l_fork);
		pthread_mutex_lock(&(philo->rules->forks_mutex[looped]));
	}
	/*
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("philo->l_fork = %d\n", !!philo->l_fork);
	printf("philo->position = %d\n", philo->position);
	printf("*(philo->r_fork) = %d\n", *(philo->r_fork));
	printf("*(philo->l_fork) = %d\n", *(philo->l_fork));
	printf("r_fork || l_fork == pos : %d\n", (*(philo->r_fork) != philo->position || *(philo->l_fork) != philo->position));
	printf("%4d |%3d %s\n", get_time(philo->rules),
		philo->position, "has both forks");
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	*/
	return (0);
}

static int	eat(t_philosopher *philo)
{
	if (philo->last_meal <= get_time(philo->rules) ||
		philo->rules->dead == TRUE)
		return (kill_philo(philo));
	if (thread_print(philo, "is eating"))
		return (1);
	philo->last_meal = get_time(philo->rules) + philo->rules->ttdie;
	philo->meals += 1;
	if (philo->rules->ttdie < philo->rules->tteat)
		ft_sleep(philo->rules->ttdie, philo);
	else
		ft_sleep(philo->rules->tteat, philo);
	set_fork(philo, philo->position, philo->r_fork);
	set_fork(philo, philo->position, philo->l_fork);
	if (philo->rules->max_iteration >= 0 &&
		philo->meals >= philo->rules->max_iteration)
	{
		pthread_mutex_lock(&(philo->rules->finish_mutex));
		philo->rules->finished++;
		thread_print(philo, "has finished his meals");
		printf("-----------> %d philo have finished\n", philo->rules->finished);
		pthread_mutex_unlock(&(philo->rules->finish_mutex));
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
	if (thread_print(philo, "is sleeping"))
		return (1);
	if (get_time(philo->rules) + philo->rules->ttsleep >= philo->last_meal)
		ft_sleep(philo->last_meal - get_time(philo->rules), philo);
	else
		ft_sleep(philo->rules->ttsleep, philo);
	if (thread_print(philo, "is thinking"))
		return (1);
	return (0);
}

void	*routine(void *tmp_philo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)tmp_philo;
//	printf("time is: %d - ttdie: %d\n", get_time(philo->rules), philo->last_meal);
	if (philo->position % 2)
		ft_sleep(2, philo);
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
