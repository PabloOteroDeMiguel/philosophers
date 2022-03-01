/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:47:40 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 12:17:40 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_data(t_data *data)
{
	int		i;

	data->philo = malloc(sizeof(t_philo) * (data->num_of_philo));
	data->fork = malloc(sizeof(t_fork) * (data->num_of_philo));
	i = 0;
	while (i < data->num_of_philo)
	{
		data->philo[i].name = i + 1;
		data->philo[i].alive = 1;
		data->philo[i].action = 0;
		data->philo[i].meals_need = 0;
		data->philo[i].dt = data;
		data->philo[i].time = get_time();
		data->philo[i].last_meal = data->philo[i].time;
		data->fork[i].id = i + 1;
		data->fork[i].aviable = 1;
		i++;
	}
}

int	get_data(int argc, char *argv[], t_data *data)
{
	if (ph_check_arg(argv, argc) == 1)
	{
		data->num_of_philo = ph_atoi(argv[1]);
		data->forks = data->num_of_philo;
		data->time_to_die = ph_atoi(argv[2]);
		data->time_to_eat = ph_atoi(argv[3]);
		data->time_to_sleep = ph_atoi(argv[4]);
		if (argv[5])
			data->meals = ph_atoi(argv[5]);
	}
	else
		return (1);
	if (data->num_of_philo < 0 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| data->meals < 0)
		return (1);
	data->death = 1;
	data->enough = 1;
	if (!argv[5])
		data->meals = -1;
	return (0);
}
