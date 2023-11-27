
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

void	set_table(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i].l_fork = &data->forks[i];
		i++;
	}
	i = 0;
	while (i < data->n_philo + 1)
	{
		philos[i].r_fork = philos[i].l_fork;
		i++;
	}
	philos[i].r_fork = philos[0].l_fork;
}

int	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		monitor(philo, "has taken a fork");
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		monitor(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(philo->r_fork))
			return (0);
		monitor(philo, "has taken a fork");
		if (pthread_mutex_lock(philo->l_fork))
			return (0);
		monitor(philo, "has taken a fork");
	}
	if (is_dead())
		return (0);
	return (1);
}
