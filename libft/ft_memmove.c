/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:47:30 by mjarry            #+#    #+#             */
/*   Updated: 2021/10/19 09:55:53 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;
	size_t		i;

	dst1 = (char *)dst;
	src1 = (const char *)src;
	if (!len || dst == src)
		return (dst);
	i = -1;
	if (dst > src)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	else
	{
		while (++i < len)
			dst1[i] = src1[i];
	}
	return (dst);
}
