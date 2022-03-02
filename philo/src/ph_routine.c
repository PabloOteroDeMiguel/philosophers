/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:34:31 by potero-d          #+#    #+#             */
/*   Updated: 2022/03/01 17:30:26 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exception(t_philo *philo)
{
	pthread_mutex_lock(&philo->dt->fork[0].fork_mutex);
	if (philo->dt->death != 0 && philo->dt->enough != 0)
		printf("%zu %d has taken a fork\n",
			get_time() - philo->time, philo->name);
	if (philo->dt->num_of_philo == 1)
	{
		do_time(philo->dt->time_to_die, philo->dt);
		pthread_mutex_unlock(&philo->dt->fork[philo->name - 1].fork_mutex);
		pthread_mutex_unlock(&philo->dt->fork[philo->name].fork_mutex);
		return ;
	}
	pthread_mutex_lock(&philo->dt->fork[philo->name - 1].fork_mutex);
	if (philo->dt->death != 0)
		printf("%zu %d has taken a fork\n",
			get_time() - philo->time, philo->name);
	if (philo->dt->death != 0)
		printf("%zu %d is eating\n",
			get_time() - philo->time, philo->name);
	philo->meals_need += 1;
	do_time(philo->dt->time_to_eat, philo->dt);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->dt->fork[0].fork_mutex);
	pthread_mutex_unlock(&philo->dt->fork[philo->name - 1].fork_mutex);
}

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (data->time_to_die < (get_time() - data->philo[i].last_meal))
		{
			printf("%zu %d died\n",
				get_time() - data->philo[i].time, data->philo[i].name);
			data->death = 0;
			break ;
		}
		i++;
	}
	if (data->death == 0)
		return (0);
	return (1);
}

int	check_meal(t_data *data)
{
	int	i;
	int	meal;

	i = 0;
	meal = 0;
	while (i < data->num_of_philo)
	{
		if (data->philo[i].meals_need >= data->meals && data->meals != -1)
			meal++;
		i++;
	}
	if (meal == data->num_of_philo)
	{
		data->enough = 0;
		stop(data);
		return (0);
	}
	return (1);
}

void	normal(t_philo *philo)
{
	pthread_mutex_lock(&philo->dt->fork[philo->name - 1].fork_mutex);
	if (philo->dt->death != 0 && philo->dt->enough != 0)
		printf("%zu %d has taken a fork\n",
			get_time() - philo->time, philo->name);
	pthread_mutex_lock(&philo->dt->fork[philo->name].fork_mutex);
	if (philo->dt->death != 0)
		printf("%zu %d has taken a fork\n",
			get_time() - philo->time, philo->name);
	if (philo->dt->death != 0)
	{
		printf("%zu %d is eating\n",
			get_time() - philo->time, philo->name);
		philo->meals_need += 1;
	}
	do_time(philo->dt->time_to_eat, philo->dt);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->dt->fork[philo->name - 1].fork_mutex);
	pthread_mutex_unlock(&philo->dt->fork[philo->name].fork_mutex);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = p;
	if (philo->name % 2 == 0)
		do_time(1, philo->dt);
	while (philo->dt->death != 0 && philo->dt->enough != 0)
	{
		pthread_mutex_lock(&philo->mutex_philo);
		if (philo->name == philo->dt->num_of_philo && philo->dt->death != 0)
			exception(philo);
		if (philo->name != philo->dt->num_of_philo && philo->dt->death != 0)
			normal(philo);
		pthread_mutex_unlock(&philo->mutex_philo);
		if (philo->dt->death != 0 && philo->dt->enough != 0
			&& philo->dt->num_of_philo != 1)
			printf("%zu %d is sleeping\n",
				get_time() - philo->time, philo->name);
		do_time(philo->dt->time_to_sleep, philo->dt);
		if (philo->dt->death != 0 && philo->dt->enough != 0
			&& philo->dt->num_of_philo != 1)
			printf("%zu %d is thinking\n",
				get_time() - philo->time, philo->name);
	}
	return (0);
}
