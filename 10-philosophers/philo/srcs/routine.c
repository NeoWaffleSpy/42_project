/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/11 16:30:21 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	set_fork(t_philosopher *philo, int pos, int *fork)
{
	if (fork == NULL)
		return (1);
	else if (*fork == pos)
		*fork = 0;
	else if (*fork == 0)
	{
		*fork = pos;
		if (thread_print(philo, "has taken a fork"))
			return (1);
	}
	else
		return (1);
	return (0);
}

static int	take_fork(t_philosopher *philo)
{
	while (1)
	{
		if (check_fork(philo, philo->position - 1, philo->l_fork_pos) == 0)
			break ;
		usleep(5);
		if (philo->last_meal <= get_time(philo->rules) || check_dead(philo))
			return (kill_philo(philo));
		pthread_mutex_lock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (*(philo->r_fork) != philo->position)
			set_fork(philo, philo->position, philo->r_fork);
		pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (philo->rules->nb_philo < 2)
			continue ;
		pthread_mutex_lock(&(philo->rules->forks_mutex[philo->l_fork_pos]));
		if (*(philo->l_fork) != philo->position)
			set_fork(philo, philo->position, philo->l_fork);
		pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->l_fork_pos]));
	}
	return (0);
}

static int	eat(t_philosopher *philo)
{
	if (philo->last_meal <= get_time(philo->rules) || check_dead(philo))
		return (kill_philo(philo));
	if (thread_print(philo, "is eating"))
		return (1);
	philo->last_meal = get_time(philo->rules) + philo->rules->ttdie;
	philo->meals += 1;
	if (philo->rules->ttdie < philo->rules->tteat)
		ft_sleep(philo->rules->ttdie, philo);
	else
		ft_sleep(philo->rules->tteat, philo);
	pthread_mutex_lock(&(philo->rules->forks_mutex[philo->position - 1]));
	set_fork(philo, philo->position, philo->r_fork);
	pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->position - 1]));
	pthread_mutex_lock(&(philo->rules->forks_mutex[philo->l_fork_pos]));
	set_fork(philo, philo->position, philo->l_fork);
	pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->l_fork_pos]));
	if (philo->rules->max_iteration >= 0
		&& philo->meals >= philo->rules->max_iteration)
		return (1);
	return (0);
}

static int	sleeping(t_philosopher *philo)
{
	if (philo->last_meal <= get_time(philo->rules) || check_dead(philo))
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
	if (philo->rules->nb_philo == 1)
	{
		thread_print(philo, "has taken a fork");
		ft_sleep(philo->rules->ttdie, philo);
		thread_print(philo, "died");
	}
	else
	{
		if (philo->position % 2)
			ft_sleep(philo->rules->tteat / 10, philo);
		philo->last_meal = get_time(philo->rules) + philo->rules->ttdie;
		while (1)
		{
			if (take_fork(philo) || eat(philo) || sleeping(philo))
				break ;
		}
	}
	pthread_mutex_lock(&(philo->rules->finish_mutex));
	philo->rules->finished++;
	pthread_mutex_unlock(&(philo->rules->finish_mutex));
	return (NULL);
}
