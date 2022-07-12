/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <nathancaba.etu@outlook.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:00:40 by ncaba             #+#    #+#             */
/*   Updated: 2022/07/11 16:29:44 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define WHITE "\x1B[37m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define CYAN "\x1B[36m"
# define RESET_COLOR "\x1B[0m"

# define MAXINT 2147483647
# define MININT -2147483648

# define TRUE 1
# define FALSE 0

typedef int				t_boolean;
typedef struct s_rules	t_rules;

typedef struct s_philosopher
{
	int				position;
	int				*l_fork;
	int				*r_fork;
	int				l_fork_pos;
	int				meals;
	int				last_meal;
	t_rules			*rules;
	pthread_t		thread;
}				t_philosopher;

struct	s_rules
{
	int				nb_philo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				max_iteration;
	int				*forks;
	int				finished;
	long long		start_time;
	t_boolean		dead;
	t_philosopher	*philosophers;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	die_mutex;
};

int		set_rules(int ac, char **av, t_rules *rules);
int		init_philo(t_rules *rules);
int		init_mutex(t_rules *rules);

void	*routine(void *tmp_philo);

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		get_time(t_rules *rules);
int		call_error(char *error, char *value);
void	call_info(char *info, char *value);
void	free_all(t_rules *rules);
void	free_malloc(t_rules *rules);

int		check_dead(t_philosopher *philo);
void	ft_sleep(int time, t_philosopher *philo);
int		kill_philo(t_philosopher *philo);
int		thread_print(t_philosopher *philo, char *str);
int		check_fork(t_philosopher *philo, int pos1, int pos2);

#endif
