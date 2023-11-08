#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void	*print_even(void *count_mutex)
{
	int counter = 0;
	
	while (counter < 100)
	{
		pthread_mutex_lock(count_mutex);
		printf("%d\n", counter);
		counter += 2;
		pthread_mutex_unlock(count_mutex);
//		usleep(20);
	}
	return (NULL);
}


void	*print_odd(void *count_mutex)
{
	int counter = 1;
	
	while (counter < 100)
	{
		pthread_mutex_lock(count_mutex);
		printf("%d\n", counter);
		counter += 2;
		pthread_mutex_unlock(count_mutex);
//		usleep(20);
	}
	return (NULL);
}

int	main()
{
	pthread_mutex_t	count_mutex;
	pthread_t *tab;

	tab = malloc(sizeof(pthread_t) * 2);
	pthread_mutex_init(&count_mutex, NULL);
	pthread_create(&tab[0], NULL, print_even, &count_mutex);
		//return (printf("error\n"));
	pthread_create(&tab[1], NULL, print_odd, &count_mutex);
	//	return (printf("error\n"));
	pthread_join(tab[0], NULL);
	pthread_join(tab[1], NULL);
	pthread_mutex_destroy(&count_mutex);

}
