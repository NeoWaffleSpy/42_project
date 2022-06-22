/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:40 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/22 19:00:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define WHITE "\x1B[37m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define CYAN "\x1B[36m"
# define RESET_COLOR "\x1B[0m"

# define TRUE 1
# define FALSE 0

typedef struct  s_philosopher
{
	int			    position;
	int			    *l_fork;
	int			    *r_fork;
	int			    meals;
	int			    last_meal;
    t_rules         *rules;
}			    t_philosopher;

typedef struct  s_rules
{
    int             nb_philo;
    int             ttdie;
    int             tteat;
    int             ttsleep;
    int             max_iteration;
	int				*forks;
	t_philosopher	*philosophers;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	die_mutex;
}               t_rules;

typedef int		t_boolean;

int     set_rules(int ac, char** av, t_rules* rules);
int     init_philo(t_rules *rules);
int     init_mutex(t_rules *rules);

void    routine(t_philosopher philo);

int 	ft_atoi(const char *nptr);
int	    ft_isdigit(int c);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);

int     call_error(char* error, char* value);
void	call_info(char *info, char *value);
void	free_all(t_rules *rules);

#endif