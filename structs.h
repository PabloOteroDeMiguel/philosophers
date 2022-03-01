/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:48:39 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 13:10:04 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "philo.h"

typedef struct s_data
{
	int				num_of_philo;
	int				forks;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				death;
	int				enough;
	struct s_fork	*fork;
	struct s_philo	*philo;
	pthread_mutex_t	mutex;
}	t_data;

typedef struct s_fork
{
	int				id;
	int				aviable;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef struct s_philo
{
	int				name;
	int				alive;
	int				action;
	int				meals_need;
	size_t			last_meal;
	size_t			time;
	struct s_data	*dt;
	pthread_t		p;
	pthread_mutex_t	mutex_philo;
}	t_philo;

#endif
