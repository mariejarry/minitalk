/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:50:34 by mjarry            #+#    #+#             */
/*   Updated: 2021/09/16 11:21:04 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s_len;
	int		i;
	char	*copy;

	s_len = ft_strlen(s1);
	copy = malloc(sizeof(char) * (s_len + 1));
	i = -1;
	if (copy == NULL)
		return (0);
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}
