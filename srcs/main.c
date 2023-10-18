/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:04:41 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/18 23:23:53 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

void	*print_message(void *bjr)
{
	(void)bjr;
	printf("ca fait plaisir quand meme\n");
	return (bjr);
}



int	main(void)
{
	pthread_t	thread;
	int			thread_return;
	
	thread_return = pthread_create(&thread, NULL, print_message, NULL);
	dprintf(2, "thread return status %d\n", thread_return);
	printf("je suis pas sur\n");
	if (pthread_join(thread, NULL))
		dprintf(2, "Erreur !");
}
