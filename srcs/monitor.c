
#include "philo.h"
#include "struct.h"
#include "includes.h"

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	monitor(t_data *data, t_philo *philo, char *status)
{
	int	time_stamp;

	time_stamp = get_time() - data->begin_time;
	printf("%d %d %s\n", time_stamp, philo->id, status);

}
