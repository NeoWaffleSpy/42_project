/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:31 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/22 19:00:32 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void thread_print(t_philosopher philo, char *str)
{
    pthread_mutex_lock(&(philo->rules->print_mutex));
    printf("%d %3d %s\n", get_time(), philo->position, str);
    pthread_mutex_unlock(&(philo->rules->print_mutex));
}
static int  eat(t_philosopher *philo)
{
    if (philo->last_meal <= get_time())
        return (1);
    thread_print(philo, "is eating");
    philo->last_meal += 1;
}

void    routine(t_philosopher *philo)
{
    philo->last_meal += get_time();
    while (1)
    {
        if (philo->rules->max_iteration >= 0 &&
            philo->meals >= philo->rules->max_iteration)
            break;
        if (take_fork(philo))
    }
}