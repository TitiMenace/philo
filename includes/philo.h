/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/10/23 17:50:16 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes.h"
# include "struct.h"


/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/main.c                             */
/* -------------------------------------------------------------------------- */
bool	init_data(t_data *data, int ac, char **av);
int	main(int ac, char **av);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/philo_utils.c                          */
/* -------------------------------------------------------------------------- */
int	ft_atoi(const char *str);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/error_management.c                       */
/* -------------------------------------------------------------------------- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
bool	check_digit(char **av);
bool	check_negative(t_data *data, int ac);


#endif
