/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:16:56 by kistod            #+#    #+#             */
/*   Updated: 2023/01/17 18:21:04 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->nb_thread;
	if (main->nb_time_to_eat > 0)
	{
		while (main->nb_time_to_eat > main->philo[i].nb_time_ate
				&& main->philo_dead == FALSE)
				routine_execute(main, i);
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (routine_execute(main, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eat(main, i) == FALSE)
		return (FALSE);
	if (main->nb_time_to_eat != main->philo[i].nb_time_ate)
	{
		if (philo_sleep(main, i) == FALSE)
			return (FALSE);
		if (philo_think(main, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	*checker(void *args)
{
	t_main *main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->nb_time_to_eat > 0)
	{
		while (main->nb_time_to_eat > main->philo[i].nb_time_ate
				&& main->philo_dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (philo_is_dead(main, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}