/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:51 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

int	get_time_to_sleep(t_data *data)
{
	if (data->time_to_sleep < data->time_to_eat && data->n_philo % 2)
		return ((data->time_to_eat - data->time_to_sleep) * 1000 + 1);
	else
		return (1);
}

bool	init_data(t_data *data, int ac, char **av)
{
	if (ac < 5)
		return (ft_putendl_fd("philo : Missing arguments !", 2), false);
	if (ac > 6)
		return (ft_putendl_fd("philo : Too many arguments !", 2), false);
	if (!check_digit(av))
		return (ft_putendl_fd("philo : Numeric arguments is required !", 2), false);
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eat_counter = ft_atoi(av[5]);
	if (!check_negative(data, ac))
		return (ft_putendl_fd("philo : Positive value is required !", 2), false);
	data->begin_time = get_time();
	data->time_to_wait = get_time_to_sleep(data);
	data->died = 0;	
	data->n_philo_has_eaten = 0;


	return (true);
}

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

t_data	*_data(void)
{
	static	t_data d;
	
	return(&d); 
}

bool	join_philo(t_philo * philos)
{
	t_data	*data;
	int	i;

	data = _data();
	i = 0;
	while (i < data->n_philo)
	{
		if(!pthread_join(*philos[i].thread, NULL))
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit(t_philo *philo)
{
	t_data	*data;
	int	i;

	data = _data();
	i = 0;
	while (i < data->n_philo && philo->thread)
	{
		free(philo[i].thread);
		i += 2;
	}
	i = 1;
	while (i < data->n_philo && philo->thread)
	{
		free(philo[i].thread);
		i += 2;
	}
	pthread_mutex_destroy(&data->has_eaten_mutex);
	pthread_mutex_destroy(&data->time_remain_mutex);
	pthread_mutex_destroy(data->forks);
	pthread_mutex_destroy(&data->output);
	free(data->forks);
	free(philo);
	pthread_mutex_destroy(&data->n_eaten_mutex);
	pthread_mutex_destroy(&data->died_mutex);
	return (0);
}



int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philos;

	data = _data();
	if (!init_data(data, ac, av))
		return (0);
	if (!init_mutexes)
		return (0);
	if (!init_forks_tab(data))
		return (0);
	philos = init_philo(philos, data);
	if (!philos)
		return (ft_exit(philos), ft_putendl_fd("philo : call_system failure !", 2), 1);
	loop(philos);
	pthread_mutex_unlock(&data->output);
	if (!join_philo(philos))
		return (ft_exit(philos), 1);
	return (ft_exit(philos));
}
