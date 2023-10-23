/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:33 by tschecro          #+#    #+#             */
/*   Updated: 2023/10/23 17:34:12 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "struct.h"
#include "includes.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

bool	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][0] == '-' && av[i][1] >= '0' && av[i][1] <= '9')
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}
