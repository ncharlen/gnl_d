/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:42:33 by ncharlen          #+#    #+#             */
/*   Updated: 2019/09/19 19:35:11 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		tot;
	char	*str;
	char	*ptr;

	i = 0;
	j = 0;
	str = (char*)s;
	if (!s)
		return (NULL);
	while (str[i])
		i++;
	while (str[j] == ' ' || str[j] == '\n' || str[j] == '\t')
		j++;
	while (str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\t')
		i--;
	tot = i - j;
	if (tot < 0)
		tot = 0;
	if ((ptr = (char*)malloc(sizeof(char) * tot + 1)) == NULL)
		return (NULL);
	ft_strncpy(ptr, &s[j], tot);
	ptr[tot] = '\0';
	return (ptr);
}
