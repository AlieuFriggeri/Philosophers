/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:52:10 by kistod            #+#    #+#             */
/*   Updated: 2023/03/27 12:25:18 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

# define NUM_ARGS "ERROR: The number of argments must be 4 or 5"
# define HELP "The number of argments must be 4 or 5:\n\
- arg1 number of philosophers\n\
- arg2 time to die\n\
- arg3 time to eat\n\
- arg4 time to sleep\n\
- arg5 number of times each philosopher must eat (optional)"

# define NUM_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in number of philosophers"
# define ARG2 "ERROR: There is a mistake in time to die"
# define ARG3 "ERROR: There is a mistake in time to eat"
# define ARG4 "ERROR: There is a mistake in time to sleep"
# define ARG5 "ERROR: There is a mistake in number of times each \
philosopher must eat"

typedef struct s_fork{
	int	left;
	int	right;
}	t_fork;

typedef struct s_philo{
	int			id;
	int			last_meal;
	int			time_to_eat;
	int			time_to_sleep;
	long long	time_to_die;
	int			dead;
	int			nb_time_ate;
	pthread_t	thread;
	t_fork		forks;
}	t_philo;

typedef struct s_main{
	int				nb_thread;
	int				numphilo;
	int				philo_dead;
	long long		t0;	
	int				nb_time_to_eat;
	t_philo			*philo;
	pthread_t		waiter;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	ate;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nb_time_ate;
}	t_main;

int			init_philo(t_main *main);
void		fill_philo(t_main *main, int i, int j);
int			ft_atoi(const char *str);
int			init_forks(t_main *main);
void		unlock_forks(t_main *main);
int			create_threads(t_main *main);
int			join_threads(t_main *main);
int			destroy_mutex(t_main *main);
int			philo_print(t_main *main, int id, char *status);
void		exec_action(long long time);
int			philo_eat(t_main *main, int i);
int			philo_sleep(t_main *main, int i);
int			philo_think(t_main *main, int i);
int			drop_forks(t_main *main, int i);
long long	gettime(void);
long long	delta_time(long long time);
int			routine_execute(t_main *main, int i);
void		*routine(void *args);
int			philo_is_dead(t_main *main, int *i);
void		*checker(void *args);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			error_manager(char **argv, int argc, t_main *main);
int			init_main(t_main *main, char **argv, int argc);
int			ft_strlen(const char *str);
void		print_args_error(t_main *main, int argc);
int			only_one(t_main *main);
void		free_philo(t_main *main);
void		nsleep(unsigned long long to_wait);
#endif