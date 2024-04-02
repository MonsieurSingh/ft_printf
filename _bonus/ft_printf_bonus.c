/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:50:22 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/02 03:59:17 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	init_data(t_data *data, const char *str)
{
	data->bytes_printed = 0;
	data->s = str;
	data->buffer = (char *)malloc(BUFF_SIZE * sizeof(char));
	if (NULL == data->buffer)
		return (MALLOC_ERROR);
	data->buffer_index = 0;
	ft_bzero(data->buffer, BUFF_SIZE * sizeof(char));
	return (OK);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	va_start(data.ap, str);
	if (init_data(&data, str))
		return (-1);
	while (*data.s)
	{
		if ('%' == *data.s && *(++data.s))
		{
			if (parse_data(&data))
				return (PARSE_ERROR);
			render_data(&data);
		}
		else
			write_buffer(&data, *data.s);
		data.s++;
	}
	flush_buffer(&data);
	va_end(data.ap);
	free(data.buffer);
	return (data.bytes_printed);
}
