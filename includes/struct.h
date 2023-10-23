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


typedef struct s_data
{
	int	nb_of_philo;
	int	time_to_die;
	int time_to_eat;
	int	time_to_sleep;
	int	eat_counter;
}			t_data;

#endif
