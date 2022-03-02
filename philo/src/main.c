/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:31:18 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 12:54:47 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks(void)
{
	system("leaks philo");
}

void	ph_error(int n)
{
	if (n == 0)
		printf("Error\nBad argument\n");
	else if (n == 1)
		printf("Error\nBad number of arguments\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		ph_error(1);
		return (1);
	}
	if (get_data(argc, argv, &data) == 1)
	{
		ph_error(0);
		return (1);
	}
	philo_data(&data);
	philo_thread(&data);
	free(data.philo);
	free(data.fork);
	return (0);
}	
