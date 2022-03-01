/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:33:08 by potero-d          #+#    #+#             */
/*   Updated: 2022/03/01 13:09:03 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	do_time(size_t time_to)
{
	size_t	time0;
	size_t	time1;

	time0 = get_time();
	time1 = get_time();
	while (time1 - time0 < time_to)
	{
		usleep(500);
		time1 = get_time();
	}
}
