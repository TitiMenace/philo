
#include "philo.h"
#include "struct.h"
#include "includes.h"

int	is_dead(void)
{
	t_data *data;

	data = _data();
	pthread_mutex_lock(&data->has_eaten_mutex);
	if (data->n_philo_has_eaten == data->n_philo)
	{
		pthread_mutex_unlock(&data->has_eaten_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->has_eaten_mutex);
	pthread_mutex_lock(&data->died_mutex);
	if (data->died)
	{
		pthread_mutex_unlock(&data->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->died_mutex);
	return (0);
}

int	thinking(t_philo *philo)
{
	t_data *data;

	data = _data();
	if (is_dead())
		return (0);
	monitor(data, philo, "is thinking");
	waiting(data->time_to_wait);
	if (is_dead())
		return (0);
	return (1);
}

int	eating(t_philo *philo)
{
	t_data	*data;

	data = _data();
	if (is_dead())
		return (0);
	monitor(data, philo, "is eating");
	if (!waiting(data->time_to_eat * 1000))
		return (0);
	if (is_dead())
		return (0);
	return (1);
}

int	sleeping(t_philo *philo)
{
	t_data *data;

	data = _data();
	if (is_dead())
		return (0);
	monitor(data, philo, "is sleeping");
	if (!waiting(data->time_to_sleep * 1000))
		return (0);
	if (is_dead())
		return (0);
}


void	*routine(void *arg)
{
	t_philo	*philo;
	t_data *data;

	data = _data();
	philo = arg;

	
}
