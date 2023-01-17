/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:12:59 by kistod            #+#    #+#             */
/*   Updated: 2023/01/17 18:51:22 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = FALSE;
	main->t0 = gettime();
	if (pthread_mutex_init(&main->print, NULL) != 0)
		return (FALSE);
	while (i < main->numphilo)
	{
		main->nb_thread = i;
		if (pthread_create(&main->philo[i].thread,
				NULL, &routine, (void *) main) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->waiter, NULL, &checker, (void *) main) != 0)
		return (FALSE);
	usleep(1000);
	if (join_threads(main) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->numphilo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_join(main->waiter, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	destroy_mutex(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->numphilo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->print);
	return (TRUE);
}
