/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2021/10/19 15:08:54 by rmechety         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes.h"
# include "struct.h"


/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/error_management.c                       */
/* -------------------------------------------------------------------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
bool	check_digit(char **av);
bool	check_negative(t_data *data, int ac);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/routine.c                            */
/* -------------------------------------------------------------------------- */
int	is_dead(void);
int	thinking(t_philo *philo);
int	eating(t_philo *philo);
int	sleeping(t_philo *philo);
void	*routine(void *arg);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/philo_utils.c                          */
/* -------------------------------------------------------------------------- */
int	ft_atoi(const char *str);

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/main.c                             */
/* -------------------------------------------------------------------------- */
int	get_time_to_sleep(t_data *data);
bool	init_data(t_data *data, int ac, char **av);
void	print_args(t_data *data, int ac);
int	philo_create(t_philo *philo, int i);
int	init_mutexes(t_data *data);
t_philo	*init_philo(t_philo *philos, t_data *data);
int	setup_routine(t_data *data, t_philo *philos);
t_data	*_data(void);
bool	join_philo(t_philo * philos);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/fork.c                             */
/* -------------------------------------------------------------------------- */
int	init_forks_tab(t_data *data);
int	set_table(t_data *data, t_philo *philos);
int	get_forks(t_philo *philo);
int	unlock_forks(t_philo *philo);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/checking.c                           */
/* -------------------------------------------------------------------------- */
int	check_food(t_philo *philo);
int	check_death(t_philo *philo);
int	loop(t_philo *philos);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/monitor.c                            */
/* -------------------------------------------------------------------------- */
int	get_time(void);
void	monitor(t_data *data, t_philo *philo, char *status);
int	waiting(int time);


#endif
