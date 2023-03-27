/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:37:30 by kistod            #+#    #+#             */
/*   Updated: 2023/03/27 12:59:46 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	init_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->numphilo + 1);
	if (main->forks == NULL)
		return (FALSE);
	i = 0;
	while (i < main->numphilo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_mutex_init(&main->ate, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->numphilo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}
