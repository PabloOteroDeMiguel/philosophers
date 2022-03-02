/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:45:13 by potero            #+#    #+#             */
/*   Updated: 2022/03/01 13:17:16 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_num(unsigned long long n, int c)
{
	if (n > 2147483647)
		return (-1);
	return (n * c);
}

long int	ph_atoi(const char *str)
{
	int			i;
	long int	n;
	long int	c;

	i = 0;
	while ((str[i] == ' ') || (str[i] > 8 && str[i] < 14))
		i++;
	c = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			c = -1;
		i++;
	}
	n = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n = n * c;
	return (ft_num(n, c));
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ph_check_arg(char **str, int argc)
{
	int	n;
	int	i;

	n = 1;
	while (n < argc)
	{
		i = 0;
		if (str[n][i] == '+' && (ft_strlen(str[n]) > 1))
			i++;
		while (str[n][i] != '\0')
		{
			if (str[n][i] < '0' || str[n][i] > '9')
				return (0);
			i++;
		}
	n++;
	}
	return (1);
}
