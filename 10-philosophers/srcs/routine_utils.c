/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:09:50 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/09 22:17:42 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_dead(t_philosopher *philo)
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

void	ft_sleep(int time, t_philosopher *philo)
{
	int	finish;

	finish = get_time(philo->rules) + time;
	while (get_time(philo->rules) < finish)
		usleep(10);
}

int	kill_philo(t_philosopher *philo)
{
	if (check_dead(philo))
		return (1);
	pthread_mutex_lock(&(philo->rules->die_mutex));
	philo->rules->dead = TRUE;
	pthread_mutex_unlock(&(philo->rules->die_mutex));
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("| %5d | %3d %s\n", get_time(philo->rules), philo->position, "died");
	pthread_mutex_unlock(&(philo->rules->print_mutex));
	return (1);
}

int	thread_print(t_philosopher *philo, char *str)
{
	if (check_dead(philo))
		return (1);
	pthread_mutex_lock(&(philo->rules->print_mutex));
	printf("| %5d | %3d %s\n", get_time(philo->rules), philo->position, str);
	pthread_mutex_unlock(&(philo->rules->print_mutex));
	return (0);
}

int	check_fork(t_philosopher *philo, int pos1, int pos2)
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
