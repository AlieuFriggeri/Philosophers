/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kistod <kistod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:44:31 by kistod            #+#    #+#             */
/*   Updated: 2023/01/17 18:49:54 by kistod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	error_manager(char **argv, int argc, t_main *main)
{
	if (argc == 2 && !ft_strncmp(argv[1], "help", 4)
		&& ft_strlen(argv[1]) == 4)
	{
		printf("%s\n", HELP);
		return (FALSE);
	}
	else if (init_main(main, argv, argc) == FALSE)
	{
		printf("%s\n", NUM_ARGS);
		return (FALSE);
	}
	else
	{
		print_args_error(main, argc);
		if (!main->numphilo || !main->time_to_die
			|| !main->time_to_eat || !main->time_to_sleep
			|| (argc == 6 && !main->nb_time_to_eat))
			return (FALSE);
	}
	return (TRUE);
}

int	init_main(t_main *main, char **argv, int argc)
{
	if (argc == 5 || argc == 6)
	{
		main->numphilo = ft_atoi(argv[1]);
		main->time_to_die = ft_atoi(argv[2]);
		main->time_to_eat = ft_atoi(argv[3]);
		main->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			main->nb_time_to_eat = ft_atoi(argv[5]);
		else
			main->nb_time_to_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t	i;

	i = 0;
	if (n == 0 || (ft_strlen(s1) == 0 && ft_strlen(s2) == 0))
		return (0);
	if (ft_strlen(s1) == 0)
		return (-1);
	if (ft_strlen(s2) == 0)
		return (1);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_args_error(t_main *main, int argc)
{
	if (!main->numphilo)
		printf("%s\n", ARG1);
	if (!main->time_to_die)
		printf("%s\n", ARG2);
	if (!main->time_to_eat)
		printf("%s\n", ARG3);
	if (!main->time_to_sleep)
		printf("%s\n", ARG4);
	if (argc == 6 && !main->nb_time_to_eat)
		printf("%s\n", ARG5);
}
