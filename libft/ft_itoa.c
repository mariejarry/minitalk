/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 08:59:45 by mjarry            #+#    #+#             */
/*   Updated: 2021/10/21 19:54:37 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	digitcounter(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n < -9 || n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		nb_digits;
	long	num;

	num = n;
	nb_digits = digitcounter(n);
	number = malloc(sizeof(char) * (nb_digits + 1));
	if (!number)
		return (NULL);
	if (num < 0)
		num *= -1;
	number[nb_digits] = '\0';
	while (nb_digits--)
	{
		number[nb_digits] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		number[0] = '-';
	return (number);
}
