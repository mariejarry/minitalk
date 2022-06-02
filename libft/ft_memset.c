/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:47:43 by mjarry            #+#    #+#             */
/*   Updated: 2021/09/22 11:49:22 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*fill;

	fill = b + (len - 1);
	while (len > 0)
	{
		*(fill--) = (unsigned char)c;
		len--;
	}
	return (b);
}
