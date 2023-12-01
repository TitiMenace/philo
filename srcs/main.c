/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/11/30 23:23:03 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

t_data	*_data(void)
{
	static t_data	d;

	return (&d);
}

int	join_philo(t_philo *philos)
{
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(*philos[i].thread, NULL);
		i++;
	}
	return (1);
}

int	ft_exit(t_philo *philo)
{
	t_data	*data;
	int		i;

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

int last_check(t_data *data, int ac)
{
	if (data->n_philo == 0)
		return (0);
	if (ac == 6 && data->eat_counter == 0)
		return (0);
	return (1);
}


int	main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philos;

	philos = NULL;
	data = _data();
	if (!init_data(data, ac, av))
		return (1);
	if (!last_check(data, ac))
		return (1);
	if (_data()->n_philo == 1)
		return (printf("0 1 is thinking\n"), usleep(_data()->time_to_die \
				* 1000), printf("%d 1 died\n", _data()->time_to_die));
	if (!init_mutexes(data))
		return (1);
	if (!init_forks_tab(data))
		return (1);
	philos = init_philo(philos, data);
	if (!philos)
		return (ft_exit(philos), ft_putendl_fd("philo : call_system failure !",
				2), 1);
	loop(philos);
	pthread_mutex_unlock(&data->output);
	join_philo(philos);
	return (ft_exit(philos), 0);
}
