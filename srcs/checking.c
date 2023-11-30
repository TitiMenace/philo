/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:39:37 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 22:39:39 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

int	check_food(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->has_eaten_mutex);
	if (philo->has_eaten == 1)
	{
		data->n_philo_has_eaten++;
		if (data->n_philo_has_eaten == data->n_philo)
		{
			pthread_mutex_unlock(&data->has_eaten_mutex);
			return (0);
		}
		philo->has_eaten = -1;
	}
	pthread_mutex_unlock(&data->has_eaten_mutex);
	return (1);
}

int	check_death(t_philo *philo)
{
	t_data	*data;

	data = _data();
	pthread_mutex_lock(&data->time_remain_mutex);
	if ((get_time() - data->begin_time) > philo->time_remain)
	{
		pthread_mutex_unlock(&data->time_remain_mutex);
		monitor(data, philo, "died");
		pthread_mutex_lock(&data->died_mutex);
		data->died = 1;
		pthread_mutex_unlock(&data->died_mutex);
		return (0);
	}
	pthread_mutex_unlock(&data->time_remain_mutex);
	return (1);
}

int	loop(t_philo *philos)
{
	int		i;
	t_data	*data;

	data = _data();
	i = 0;
	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if (!check_food(philos + i))
				return (pthread_mutex_lock(&data->output), 0);
			if (!check_death(philos + i))
				return (pthread_mutex_lock(&data->output), 0);
			i++;
		}
		usleep(400);
	}
}
