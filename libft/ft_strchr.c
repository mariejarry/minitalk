/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:48:58 by mjarry            #+#    #+#             */
/*   Updated: 2021/09/16 10:27:17 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	if (c == 0)
	{
		while (*s != 0)
			s++;
		return ((char *)s);
	}
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s == '\0')
		return (NULL);
	else
		return ((char *)s);
}
