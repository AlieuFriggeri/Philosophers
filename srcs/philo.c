/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:52:22 by kistod            #+#    #+#             */
/*   Updated: 2023/01/17 18:50:31 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (error_manager(argv, argc, &main) == FALSE)
		return (1);
	if (init_philo(&main) == FALSE)
		return (1);
	if (init_forks(&main) == FALSE)
		return (1);
	if (main.numphilo == 1)
	{
		if (only_one(&main) == FALSE)
			return (1);
		return (0);
	}
	if (create_threads(&main) == FALSE)
		return (1);
	if (destroy_mutex(&main) == FALSE)
		return (1);
	free_philo(&main);
	return (0);
}

int	philo_print(t_main *main, int id, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	if (main->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->print);
	if (main->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&main->print);
		return (FALSE);
	}
	else
		printf("%lld %d %s\n", now, id, status);
	pthread_mutex_unlock(&main->print);
	return (TRUE);
}

void	free_philo(t_main *main)
{
	free(main->philo);
	free(main->forks);
}

int	only_one(t_main *main)
{
	if (pthread_mutex_init(&main->print, NULL) != 0)
		return (FALSE);
	main->t0 = gettime();
	philo_print(main, 1, FORK);
	exec_action(main->time_to_die);
	philo_print(main, 1, DIED);
	free_philo(main);
	return (TRUE);
}
