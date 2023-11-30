/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:06:00 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/23 16:29:10 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include "philo.h"
# include "struct.h"

# ifndef BUFFER_SIZE_H
#  define BUFFER_SIZE 42
# endif

# include <stdbool.h> 
# include <limits.h> 
# include <pthread.h> 
# include <sys/wait.h> 
# include <sys/time.h>
# include <fcntl.h> 
# include <unistd.h> 
# include <stdio.h> 
# include <stdlib.h> 
# include <stddef.h>

#endif
