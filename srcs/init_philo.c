/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:42:08 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 22:42:44 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

int	philo_create(t_philo *philo, int i)
{
	philo->thread = malloc(sizeof(pthread_t));
	if (!philo->thread)
		return (0);
	philo->n_meals = 0;
	philo->id = i + 1;
	philo->has_eaten = 0;
	philo->time_remain = _data()->time_to_die;
	if (pthread_create(philo->thread, NULL, &routine, philo))
		return (0);
	return (1);
}

t_philo	*init_philo(t_philo *philos, t_data *data)
{
	int	i;

	philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!philos || !set_table(data, philos))
		return (NULL);
	i = 0;
	data->begin_time = get_time();
	while (i < data->n_philo)
	{
		usleep(100);
		if (!philo_create(&philos[i], i))
			return (NULL);
		i += 2;
	}
	i = 1;
	while (i < data->n_philo)
	{
		if (!philo_create(&philos[i], i))
			return (NULL);
		i += 2;
	}
	return (philos);
}
