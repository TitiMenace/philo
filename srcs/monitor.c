/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:40:25 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 22:48:57 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	monitor(t_data *data, t_philo *philo, char *status)
{
	if (is_dead())
		return ;
	pthread_mutex_lock(&data->output);
	if (is_dead())
	{
		pthread_mutex_unlock(&data->output);
		return ;
	}
	printf("%d %d %s\n", get_time() - data->begin_time, philo->id, status);
	pthread_mutex_unlock(&data->output);
}

int	waiting(int time)
{
	int	begin;

	begin = get_time() * 1000;
	while (get_time() * 1000 - begin < time)
	{
		if (is_dead())
			return (0);
		usleep(50);
	}
	return (1);
}

int	get_time_to_sleep(t_data *data)
{
	if (data->time_to_sleep < data->time_to_eat && data->n_philo % 2)
		return ((data->time_to_eat - data->time_to_sleep) * 1000 + 1);
	else
		return (1);
}
