/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_call.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:06:42 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/02 15:58:11 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	call_error(char *error, char *value)
{
	printf("%s[%sError%s]: ", WHITE, RED, WHITE);
	printf("%s %s%s%s\n", error, YELLOW, value, RESET_COLOR);
	return(1);
}

void	call_info(char *info, char *value)
{
	printf("%s[%sInfo%s]: ", WHITE, GREEN, WHITE);
	printf("%-20s %s%s%s\n", info, CYAN, value, RESET_COLOR);
}

void	free_all(t_rules *rules)
{
	int	i;

    i = 0;
    while (i < rules->nb_philo)
    {
        pthread_mutex_destroy(&(rules->forks_mutex[i]));
        i++;
    }
	pthread_mutex_destroy(&(rules->print_mutex));
	pthread_mutex_destroy(&(rules->die_mutex));
	free(rules->philosophers);
	free(rules->forks);
	free(rules->forks_mutex);
}