/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:41:52 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 22:44:49 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

bool	init_data(t_data *data, int ac, char **av)
{
	if (ac < 5)
		return (ft_putendl_fd("philo : Missing arguments !", 2), false);
	if (ac > 6)
		return (ft_putendl_fd("philo : Too many arguments !", 2), false);
	if (!check_digit(av))
		return (ft_putendl_fd("philo : Numeric arguments is required !",
				2), false);
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->eat_counter = -1;
	if (ac == 6)
		data->eat_counter = ft_atoi(av[5]);
	if (!check_negative(data, ac))
		return (ft_putendl_fd("philo : Wrong Args !", 2), false);
	data->begin_time = get_time();
	data->time_to_wait = get_time_to_sleep(data);
	data->died = 0;
	data->n_philo_has_eaten = 0;
	return (true);
}

int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->output, 0))
		return (0);
	if (pthread_mutex_init(&data->died_mutex, 0))
		return (0);
	if (pthread_mutex_init(&data->n_eaten_mutex, 0))
		return (0);
	if (pthread_mutex_init(&data->time_remain_mutex, 0))
		return (0);
	if (pthread_mutex_init(&data->n_eaten_mutex, 0))
		return (0);
	if (pthread_mutex_init(&data->has_eaten_mutex, 0))
		return (0);
	return (1);
}
