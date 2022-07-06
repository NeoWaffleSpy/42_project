/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/06 18:56:45 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	check_dead(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->rules->die_mutex));
	if (philo->rules->dead == TRUE)
	{
		pthread_mutex_unlock(&(philo->rules->die_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	return (0);
}

static void	ft_sleep(int time, t_philosopher *philo)
{
	int	finish;

	finish = get_time(philo->rules) + time;
	while (get_time(philo->rules) < finish)
		usleep(10);
}

static int	thread_print(t_philosopher *philo, char *str)
{
	if (check_dead(philo))
		return (1);
	pthread_mutex_lock(&(philo->rules->print_mutex));
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
	if (check_dead(philo))
		return (1);
	pthread_mutex_lock(&(philo->rules->die_mutex));
	philo->rules->dead = TRUE;
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("| %3d | %3d %s\n", get_time(philo->rules), philo->position, "died");
//	ft_printf(get_time(philo->rules), philo->position, "died");
	pthread_mutex_unlock(&(philo->rules->print_mutex));
	return (1);
}

static int	check_fork(t_philosopher *philo, int pos1, int pos2)
{
	int	ret;

	ret = 2;
	pthread_mutex_lock(&(philo->rules->forks_mutex[pos1]));
	if (*(philo->r_fork) == philo->position)
		ret--;
	pthread_mutex_unlock(&(philo->rules->forks_mutex[pos1]));
	pthread_mutex_lock(&(philo->rules->forks_mutex[pos2]));
	if (*(philo->l_fork) == philo->position)
		ret--;
	pthread_mutex_unlock(&(philo->rules->forks_mutex[pos2]));
	return (ret);
}

static int	take_fork(t_philosopher *philo)
{
	int	looped;

	if (philo->position == philo->rules->nb_philo)
		looped = 0;
	else
		looped = philo->position;
	while (1)
	{
		if (philo->l_fork != NULL &&
			check_fork(philo, philo->position - 1, looped) == 0)
			break;
		usleep(5);
		if (philo->last_meal <= get_time(philo->rules) || check_dead(philo))
			return (kill_philo(philo));
		pthread_mutex_lock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (*(philo->r_fork) != philo->position)
			set_fork(philo, philo->position, philo->r_fork);
		pthread_mutex_unlock(&(philo->rules->forks_mutex[philo->position - 1]));
		if (philo->rules->nb_philo < 2)
			continue;
		pthread_mutex_lock(&(philo->rules->forks_mutex[looped]));
		if (*(philo->l_fork) != philo->position)
			set_fork(philo, philo->position, philo->l_fork);
		pthread_mutex_unlock(&(philo->rules->forks_mutex[looped]));
	}
	return (0);
}

static int	eat(t_philosopher *philo)
{
	int	looped;

	if (philo->position == philo->rules->nb_philo)
		looped = 0;
	else
		looped = philo->position;
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
	pthread_mutex_lock(&(philo->rules->forks_mutex[looped]));
	set_fork(philo, philo->position, philo->l_fork);
	pthread_mutex_unlock(&(philo->rules->forks_mutex[looped]));
	if (philo->rules->max_iteration >= 0 &&
		philo->meals >= philo->rules->max_iteration)
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
	if (philo->position % 2)
		ft_sleep(1, philo);
	while (1)
	{
		if (philo->rules->max_iteration >= 0 &&
				philo->meals >= philo->rules->max_iteration)
			break;
		if (take_fork(philo) || eat(philo) || sleeping(philo))
			break;
	}
	pthread_mutex_lock(&(philo->rules->finish_mutex));
	philo->rules->finished++;
	pthread_mutex_unlock(&(philo->rules->finish_mutex));
	return (NULL);
}
