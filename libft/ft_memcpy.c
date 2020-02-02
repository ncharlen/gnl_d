/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:42:44 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/19 19:18:11 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (n == 0 || dst == src)
		return (dst);
	ptr = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	while (n > 0)
	{
		*(ptr) = *(ptr2);
		n--;
		ptr++;
		ptr2++;
	}
	return (dst);
}
