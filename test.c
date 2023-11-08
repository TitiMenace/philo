#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_counter
{
	pthread_mutex_t	count_mutex;
	unsigned int	count;
}			t_counter;

void	*print_even(void *data)
{
	t_counter	*counter;
	
	counter = (t_counter *)data;
	while (counter->count < 100)
	{
		pthread_mutex_lock(&counter->count_mutex);
		printf("%d\n", counter->count);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	return (NULL);
}

void	*print_odd(void *data)
{
	t_counter	*counter;

	counter = (t_counter *)data;
	while (counter->count < 100)
	{
		pthread_mutex_lock(&counter->count_mutex);
		printf("%d\n", counter->count);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	return (NULL);
}

int	main()
{
	t_counter counter;
	pthread_t *tab;

	tab = malloc(sizeof(pthread_t) * 2);
	counter.count = 0;
	pthread_mutex_init(&counter.count_mutex, NULL);
	pthread_create(&tab[0], NULL, print_even, &counter);
		//return (printf("error\n"));
	pthread_create(&tab[1], NULL, print_odd, &counter);
	//	return (printf("error\n"));
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_mutex_destroy(&counter.count_mutex);

}
