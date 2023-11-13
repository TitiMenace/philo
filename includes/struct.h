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
	pthread_mutex_t	*forks;

}			t_data;

typedef struct s_philo
{
	pthread_t			*thread;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	int					id;
	int					eat_counter;
}			t_philo;


#endif
