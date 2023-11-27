/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:07:36 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/23 17:28:08 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "includes.h"

# include <stdbool.h> 
# include <pthread.h> 
# include <sys/wait.h> 
# include <sys/time.h>
# include <fcntl.h> 
# include <unistd.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <stddef.h>


typedef struct s_data
{
	int	n_philo;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	eat_counter;
	int begin_time;
	int	time_to_wait;
	int	n_philo_has_eaten;
	int died;

	pthread_mutex_t	*forks;
	pthread_mutex_t	has_eaten_mutex;
	pthread_mutex_t	n_eaten_mutex;
	pthread_mutex_t	time_remain_mutex;
	pthread_mutex_t	died_mutex;
	pthread_mutex_t	output;

}			t_data;

typedef struct s_philo
{
	pthread_t			*thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	int					id;
	int					n_meals;
	int					time_remain;
	int					has_eaten;
}			t_philo;


#endif
