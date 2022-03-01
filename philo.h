/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:28:45 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 12:59:25 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<pthread.h>
# include<sys/time.h>
# include "structs.h"

int			main(int argc, char *argv[]);
void		ph_error(int i);
/*Utils*/
long int	ph_atoi(const char *str);
int			ph_check_arg(char **str, int argc);
/*Data*/
int			get_data(int argc, char *argv[], t_data *data);
void		philo_data(t_data *data);
/*Threads*/
void		philo_thread(t_data *data);
void		init_create(t_data *data);
void		stop(t_data *data);
/*Time*/
size_t		get_time(void);
void		do_time(size_t time_to);
/*Routine*/
void		*routine(void *philo);
void		exception(t_philo *philo);
int			check_death(t_data *data);
int			check_meal(t_data *data);
#endif
