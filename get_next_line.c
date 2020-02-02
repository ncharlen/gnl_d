/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharlen <ncharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:15:08 by ncharlen          #+#    #+#             */
/*   Updated: 2019/11/25 14:00:14 by ncharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			move_tail(t_gnl_contex *ctx, int tail_start, int tail_end)
{
	int				i;
	int				n;

	i = 0;
	n = tail_end - tail_start;
	while (i < n)
	{
		ctx->buf[i] = ctx->buf[tail_start + i];
		++i;
	}
	ctx->useful_data -= ctx->line_in_buf;
	ctx->pos_in_search -= ctx->line_in_buf;
	ctx->line_in_buf = 0;
	if (BUFF_SIZE >= (ctx->buf_size - ctx->useful_data))
	{
		ctx->buf_size = ctx->useful_data + BUFF_SIZE;
		ctx->buf = ft_rc(ctx->buf, ctx->buf_size + 1, ctx->useful_data);
	}
}

t_gnl_contex	*gctxfd(const int fd, t_gnl_contex **ctx_ptr, int size)
{
	int				i;
	t_gnl_contex	*tmp;

	i = 0;
	while (i < size && ctx_ptr[i] != NULL && ctx_ptr[i]->fd_value != fd)
		++i;
	if (i >= size)
		i = size - 1;
	else if (!ctx_ptr[i])
	{
		ctx_ptr[i] = malloc(sizeof(t_gnl_contex));
		ft_memset(ctx_ptr[i], 0, sizeof(t_gnl_contex));
		ctx_ptr[i]->buf = (char *)malloc(BUFF_SIZE + 1);
	}
	ctx_ptr[i]->fd_value = fd;
	tmp = ctx_ptr[i];
	while (i > 0)
	{
		ctx_ptr[i] = ctx_ptr[i - 1];
		--i;
	}
	ctx_ptr[0] = tmp;
	return (ctx_ptr[0]);
}

int				gnl_res_check(t_gnl_contex *ctx, char **line)
{
	if (ctx->useful_data == 0)
		return (0);
	ctx->buf[ctx->useful_data] = '\0';
	*line = &ctx->buf[ctx->line_in_buf];
	ctx->line_in_buf = -1;
	return (1);
}

int				gnl(t_gnl_contex *ctx, const int fd, char **line, ssize_t res)
{
	while (1)
	{
		if (ctx->pos_in_search == ctx->useful_data)
		{
			move_tail(ctx, ctx->line_in_buf, ctx->useful_data);
			if ((res = read(fd, ctx->buf + ctx->pos_in_search, BUFF_SIZE)) >= 0)
			{
				if (!res)
					return (gnl_res_check(ctx, line));
				ctx->useful_data += res;
			}
				else return (-1);
		}
		while (ctx->pos_in_search != ctx->useful_data)
		{
			if (ctx->buf[ctx->pos_in_search] == '\n')
			{
				ctx->buf[ctx->pos_in_search] = '\0';
				*line = &ctx->buf[ctx->line_in_buf];
				ctx->line_in_buf = ++ctx->pos_in_search;
				return (1);
			}
			++ctx->pos_in_search;
		}
	}
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl_contex	*ctx_ptr[FD_COUNT];
	t_gnl_contex			*ctx;
	ssize_t					res;

	res = 0;
	ctx = gctxfd(fd, ctx_ptr, FD_COUNT);
	if (fd < 0 || !line || !ctx->buf)
		return (-1);
	if (ctx->line_in_buf == -1)
		return (0);
	res = gnl(ctx, fd, line, res);
	if (res == 1)
	{
		*line = ft_strdup(*line);
	}
	return (res);
}
