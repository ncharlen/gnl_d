/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:05:17 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/19 16:56:22 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **link, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*link != NULL)
	{
		next = (*link)->next;
		ft_lstdelone(link, del);
		*link = next;
	}
}
