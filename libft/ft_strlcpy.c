/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:58:21 by mjarry            #+#    #+#             */
/*   Updated: 2021/09/14 08:58:35 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	r;
	size_t	i;

	r = -1;
	i = 0;
	while (src[i])
		i++;
	if (!dst || dstsize == 0)
		return (i);
	while (src[++r] && r < (dstsize - 1))
		dst[r] = src[r];
	dst[r] = '\0';
	return (i);
}
