
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
	if (!is_dead())
		return (0);
	pthread_mutex_lock(&data->time_remain_mutex);
	philo->time_remain = (get_time() - data->begin_time) + data->time_to_die;
	pthread_mutex_unlock(&data->time_remain_mutex);
	philo->n_meals++;
	monitor(data, philo, "is eating");
	pthread_mutex_lock(&data->has_eaten_mutex);
	if (philo->n_meals == data->eat_counter && philo->has_eaten == 0)
		philo->has_eaten = 1;
	pthread_mutex_unlock(&data->has_eaten_mutex);
	if (!waiting(data->time_to_eat * 1000))
		return (unlock_forks(philo), 0);
	unlock_forks(philo);
	if (is_dead())
		return (0);
	if (!waiting(200))
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
	return (1);
}


void	*routine(void *arg)
{
	t_philo	*philo;
	t_data *data;

	data = _data();
	philo = arg;
	philo->time_remain = data->time_to_die;
	while (!is_dead())
	{
		
		if (!thinking(philo))
			break ;
		while (!get_forks(philo) && !is_dead())
			usleep(10);
		if (is_dead())
		{
			unlock_forks(philo);
			break ;
		}
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
	}
	pthread_exit(NULL);
	return (NULL);
}
