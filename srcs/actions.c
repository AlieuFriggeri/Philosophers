/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:35:44 by kistod            #+#    #+#             */
/*   Updated: 2023/03/24 14:43:31 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	philo_eat(t_main *main, int i)
{
	main->philo[i].time_to_die = gettime();
	if (pthread_mutex_lock(&main->forks[main->philo[i].forks.right]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].forks.left]) != 0)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, FORK) == FALSE)
		return (FALSE);
	if (philo_print(main, main->philo[i].id, EAT) == FALSE)
		return (FALSE);
	exec_action(main->time_to_eat);
	drop_forks(main, i);
	main->philo[i].time_to_die = gettime();
	return (TRUE);
}

int	philo_sleep(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, SLEEP) == FALSE)
		return (FALSE);
	exec_action(main->time_to_sleep);
	return (TRUE);
}

int	philo_think(t_main *main, int i)
{
	if (philo_print(main, main->philo[i].id, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

// peut etre check si retour du unlock != 0 mais pas certains
int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].forks.right]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].forks.left]))
		return (FALSE);
	main->philo[i].nb_time_ate++;
	return (TRUE);
}

int	philo_is_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->numphilo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->time_to_die)
	{
		philo_print(main, main->philo[*i].id, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}
