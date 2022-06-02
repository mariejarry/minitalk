/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:44:06 by mjarry            #+#    #+#             */
/*   Updated: 2021/09/14 08:45:38 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst1;
	const char	*src1;

	if (dst == src || n == 0)
		return (dst);
	dst1 = (char *)dst;
	src1 = (const char *)src;
	while (n-- > 0)
		dst1[n] = src1[n];
	return (dst);
}
