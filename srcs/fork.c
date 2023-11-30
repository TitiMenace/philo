/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:38:17 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 22:39:51 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

int	init_forks_tab(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (0);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], 0))
			return (0);
		i++;
	}
	return (1);
}

int	set_table(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].l_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < data->n_philo - 1)
	{
		philos[i].r_fork = philos[i + 1].l_fork;
		i++;
	}
	philos[i].r_fork = philos[0].l_fork;
	return (1);
}

int	get_forks(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		monitor(data, philo, "has taken a fork");
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		monitor(data, philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		monitor(data, philo, "has taken a fork");
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		monitor(data, philo, "has taken a fork");
	}
	if (is_dead())
		return (0);
	return (1);
}

int	unlock_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
	return (0);
}
