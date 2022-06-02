/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:28:18 by mjarry            #+#    #+#             */
/*   Updated: 2022/06/02 09:44:03 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	catcher(int signal)
{
	static int	i;
	static int	result;

	if (signal == 30)
		result += ft_exponent(2, i);
	i++;
	if (i == 8)
	{
		write(1, &result, 1);
		result = 0;
		i = 0;
	}
	usleep(20);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, catcher);
	signal(SIGUSR2, catcher);
	while (1)
	{
	}
	return (0);
}
