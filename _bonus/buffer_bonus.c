/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:43:11 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/02 04:10:40 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	flush_buffer(t_data *data)
{
	int	i;

	i = 0;
	i += write(STDOUT_FILENO, data->buffer,
			data->buffer_index);
	if (i < 0 || data->bytes_printed < 0)
	{
		if (i < 0 && !(data->bytes_printed < 0))
			data->bytes_printed = i;
	}
	else
		data->bytes_printed = i;
	ft_bzero(data->buffer, BUFF_SIZE);
	data->buffer_index = 0;
}

void	write_buffer(t_data *data, char c)
{
	if (data->buffer_index == BUFF_SIZE)
		flush_buffer(data);
	data->buffer[data->buffer_index++] = c;
}

void	char_buffer(char c, int n, t_data *data)
{
	if (n <= 0)
		return ;
	while (n--)
		write_buffer(data, c);
	return ;
}

void	str_buffer(char *s, int n, t_data *data)
{
	if (n <= 0)
		return ;
	while (n-- && *s)
		write_buffer(data, *s++);
	return ;
}

void	nbr_buffer(t_data *data, t_nibbles u_nibble)
{
	t_nibbles	u_temp;

	u_temp.u_int64 = 0;
	if (data->format.is_negative && !(data->format.is_converted))
	{
		u_nibble.int64 = -(u_nibble.int64);
		data->format.is_converted = TRUE;
		nbr_buffer(data, u_nibble);
	}
	else if (u_nibble.u_int64 < data->format.base)
	{
		if (data->format.upper_case)
			data->format.temp_buffer[data->format.nbr_len++]
				= UPPER_HEX[u_nibble.u_int64];
		else
			data->format.temp_buffer[data->format.nbr_len++]
				= LOWER_HEX[u_nibble.u_int64];
	}
	else
	{
		u_temp.u_int64 = u_nibble.u_int64 / data->format.base;
		nbr_buffer(data, u_temp);
		u_temp.u_int64 = u_nibble.u_int64 % data->format.base;
		nbr_buffer(data, u_temp);
	}
}
