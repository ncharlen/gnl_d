/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:02:39 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/19 17:04:14 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = 0;
	while (*s)
	{
		if (*s == c)
			last = (char*)s;
		s++;
	}
	if (last)
		return (last);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
