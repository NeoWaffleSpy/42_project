/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:23:59 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/22 19:24:06 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int set_rules(int   ac, char** av, t_rules *rules)
{
    if (ac < 5 || ac > 6)
        return (call_error("Usage:", "<NbPhilo> <TimeToDie> <TimeToEat> <TimeToSleep>"));
    rules->nb_philo = ft_atoi(av[1]);
    if (rules->nb_philo <= 0)
        return (call_error("Number of philosophers incorrect:", av[1]));
    rules->ttdie = ft_atoi(av[2]);
    if (rules->ttdie < 0)
        return (call_error("Time to Die incorrect:", av[2]));
    rules->tteat = ft_atoi(av[3]);
    if (rules->tteat < 0)
        return (call_error("Time to Eat incorrect:", av[3]));
    rules->ttsleep = ft_atoi(av[4]);
    if (rules->ttsleep < 0)
        return (call_error("Time to Sleep incorrect:", av[4]));
    if (ac == 6)
    {
        rules->max_iteration = ft_atoi(av[5]);
        if (rules->max_iteration < 0)
            return (call_error("Number of times to eat Incorrect:", av[5]));
    }
    else
        rules->max_iteration = -1;
    return (0);
}

int init_philo(t_rules *rules)
{
    int i;

    rules->philosophers = malloc(sizeof(t_philosopher) * rules->nb_philo);
    rules->forks = malloc(sizeof(int) * rules->nb_philo);
	if (!rules->philosophers || !rules->forks)
        return(call_error("Malloc error in:", "init_philo"));
    i = 0;
    while (i < rules->nb_philo)
    {
        rules->forks[i] = -1;
        rules->philosophers[i].position = i;
        rules->philosophers[i].meals = 0;
        rules->philosophers[i].last_meal = rules->ttdie;
        rules->philosophers[i].r_fork = &(rules->forks[i])
        rules->philosophers[i].rules = rules;
        if (i < rules->nb_philo - 1)
            rules->philosophers[i].l_fork = &(rules->forks[i+1])
        else
            rules->philosophers[i].l_fork = &(rules->forks[0])
        i++;
    }
    return (0);
}
int init_mutex(t_rules *rules)
{
    int i;
    rules->forks_mutex = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
    if (!rules->forks_mutex)
        return(call_error("Malloc error in:", "init_mutex"));
    i = 0;
    while (i < rules->nb_philo)
    {
        pthread_mutex_init(&(rules->forks_mutex[i]), NULL);
        i++;
    }
    pthread_mutex_init(&(rules->print_mutex), NULL);
    pthread_mutex_init(&(rules->die_mutex), NULL);
    return (0);
}
