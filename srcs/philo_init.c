/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:11:31 by kistod            #+#    #+#             */
/*   Updated: 2023/01/17 18:50:14 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	init_philo(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * (main->numphilo + 1));
	if (main->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < main->numphilo)
	{
		fill_philo(main, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo(main, i, j);
	return (TRUE);
}

void	fill_philo(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].time_to_die = 0;
	main->philo[i].nb_time_ate = 0;
	main->philo[i].forks.left = i;
	main->philo[i].forks.right = j;
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (n < 0 || ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		|| n > __INT_FAST32_MAX__)
		return (0);
	return (n);
}
