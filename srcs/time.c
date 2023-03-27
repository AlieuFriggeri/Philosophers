/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:39:38 by kistod            #+#    #+#             */
/*   Updated: 2023/03/27 12:59:58 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

long long	delta_time(long long time)
{
	if (time > 0)
		return (gettime() - time);
	return (0);
}

void	exec_action(long long time)
{
	nsleep(time);
}

void	nsleep(unsigned long long to_wait)
{
	long long	target;

	target = gettime() + (to_wait);
	while (gettime() < target)
	{
		usleep(5);
	}
}
