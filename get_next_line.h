/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:13:58 by ncharlen          #+#    #+#             */
/*   Updated: 2019/11/25 14:02:00 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define FD_COUNT 1000
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_gnl_contex{
	char		*buf;
	int			line_in_buf;
	int			buf_size;
	int			useful_data;
	int			pos_in_search;
	int			fd_value;
}				t_gnl_contex;

int				get_next_line(const int fd, char **line);

#endif
