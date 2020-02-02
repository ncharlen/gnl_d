/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:48:27 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/20 13:45:42 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_cw(const char *str, char c)
{
	int word;

	word = 0;
	if (*str != c && *str)
	{
		str++;
		word++;
	}
	while (*str)
	{
		while (*str == c)
		{
			str++;
			if (*str != c && *str)
				word++;
		}
		str++;
	}
	return (word);
}

static int		ft_ln(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**str;

	j = 0;
	i = 0;
	if (!s || (!(str = (char **)malloc(sizeof(char *) * (ft_cw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(str[j] = (char *)malloc(sizeof(char) * (ft_ln(s, c) + 1))))
				return (NULL);
			while (*s && *s != c)
				str[j][i++] = (char)*s++;
			str[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	str[j] = NULL;
	return (str);
}
