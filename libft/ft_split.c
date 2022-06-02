/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:09:33 by mjarry            #+#    #+#             */
/*   Updated: 2022/04/22 14:19:09 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	wc(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*fillword(const char *s, char c)
{
	char	*wd;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (s[len] && s[len] != c)
		len++;
	wd = malloc(sizeof(char) * (len + 1));
	if (!wd)
		return (NULL);
	while (s[++i] && s[i] != c)
		wd[i] = s[i];
	wd[i] = '\0';
	return (wd);
}

static char	**freestr(char **str)
{
	while (*str)
	{
		free(*(str));
		(*str)++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		wcount;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	wcount = wc(s, c);
	str = malloc(sizeof(char *) * (wcount + 1));
	if (!str)
		return (NULL);
	while (wcount--)
	{
		while (*s && *s == c)
			s++;
		str[i] = fillword(s, c);
		if (!str[i])
			return (freestr(str));
		i++;
		while (*s && *s != c)
			s++;
	}
	str[i] = NULL;
	return (str);
}
