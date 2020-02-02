/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 10:54:01 by ncharlen          #+#    #+#             */
/*   Updated: 2019/11/24 11:00:05 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_rc(char *ptr, int new_size, int copy_size)
{
	char			*new_ptr;
	int				i;

	i = 0;
	new_ptr = (char *)malloc(new_size);
	if (!new_ptr)
		return (NULL);
	while (i < copy_size)
	{
		new_ptr[i] = ptr[i];
		++i;
	}
	free(ptr);
	return (new_ptr);
}
