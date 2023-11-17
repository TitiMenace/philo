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
	return (true);
}

void	print_args(t_data *data, int ac)
{
	
	dprintf(2, "%d\n", data->n_philo);
	dprintf(2, "%d\n", data->time_to_die);
	dprintf(2, "%d\n", data->time_to_eat);
	dprintf(2, "%d\n", data->time_to_sleep);
	if (ac == 6)
		dprintf(2, "%d\n", data->eat_counter);
}

int	philo_create(t_philo *philo, int i)
{
	philo->thread = malloc(sizeof(pthread_t));
	if (!philo->thread)
		return (0);
	philo->eat_counter = 0;
	philo->id = i + 1;
	if (pthread_create(philo->thread, NULL, &routine, (void *)philo))
		return (0);
	return (1);
}


t_philo	*init_philo(t_philo *philos, t_data *data)
{
	int	i;

	philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!philos)
		return (NULL);
	i = 0;
	data->begin_time = get_time();
	while (i < data->n_philo)
	{
		usleep(200);
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

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philos;

	if (!init_data(&data, ac, av))
		return (1);
	philos = malloc(sizeof(t_philo) * data.n_philo);
	if (!philos)
		return (ft_putendl_fd("philo : call_system failure !", 2), 1);
	return (0);
}
