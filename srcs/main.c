/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/23 17:42:03 by tschecro         ###   ########.fr       */
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
		return (ft_putendl_fd("philo : Numeric arguments required !", 2), false);
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eat_counter = ft_atoi(av[5]);
	return (true);
}


int	main(int ac, char **av)
{
	t_data	data;

	if (!init_data(&data, ac, av))
		return (1);
	dprintf(2, "%d\n", data.nb_of_philo);
	dprintf(2, "%d\n", data.time_to_die);
	dprintf(2, "%d\n", data.time_to_eat);
	dprintf(2, "%d\n", data.time_to_sleep);
	if (ac == 6)
		dprintf(2, "%d\n", data.eat_counter);
	return (0);
}
