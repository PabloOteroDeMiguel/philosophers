/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:12:38 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 13:07:13 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->fork[i].fork_mutex);
		pthread_mutex_destroy(&data->philo[i].mutex_philo);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}

void	init_create(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->fork[i].fork_mutex, NULL);
		pthread_mutex_init(&data->philo[i].mutex_philo, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_create(&data->philo[i].p, NULL, &routine, &data->philo[i]);
		i++;
	}
}

void	philo_thread(t_data *data)
{
	int			i;

	init_create(data);
	while (check_death(data) != 0)
	{
		check_meal(data);
		if (data->enough == 0)
		{
			stop(data);
			break ;
		}
	}
	if (data->death == 0 || data->enough == 0)
		stop(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->philo[i].p, NULL);
		i++;
	}
}
