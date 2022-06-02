/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:28:15 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/02 11:04:02 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	parsing(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	if (str[i] != 0)
	{
		write(2, "invalid PID\n", 13);
		return (-1);
	}	
	return (1);
}

int	pitcher(char **av)
{
	int	pid;
	int	i;
	int	j;
	int	success;

	i = -1;
	success = -1;
	pid = ft_atoi(av[1]);
	while (av[2][++i] != 0)
	{
		j = -1;
		while (++j < 8)
		{
			if ((av[2][i] >> j) & 1)
				success = kill(pid, SIGUSR1);
			else
				success = kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	return (success);
}

int	main(int ac, char **av)
{
	int	success;

	if (ac == 3)
	{
		if (parsing(av[1]) == -1)
			return (-1);
		success = pitcher(av);
		if (success == -1)
			write(1, "Message not recieved\n", 22);
		else
			write(1, "Message recieved\n", 18);
	}
	else
		write(2, "Wrong number of arguments\n", 27);
	return (0);
}
