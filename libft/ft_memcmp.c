/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:20:01 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/19 18:04:17 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chr1;
	unsigned char	*chr2;

	chr1 = (unsigned char*)s1;
	chr2 = (unsigned char*)s2;
	while (n--)
	{
		if (*chr1 != *chr2)
			return (*chr1 - *chr2);
		chr1++;
		chr2++;
	}
	return (0);
}
