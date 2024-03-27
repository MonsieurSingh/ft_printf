//
//  buffer.c
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#include "printf.h"

void	flush_buffer(t_data *data)
{
	data->bytes_printed += write(STDOUT_FILENO,
								 data->buffer,
								 data->buffer_index);
	bzero(data->buffer, BUFF_SIZE);
	data->buffer_index = 0;
}

void	write_buffer(t_data *data, char c)
{
	if (data->buffer_index == BUFF_SIZE)
		flush_buffer(data);
	data->buffer[data->buffer_index++] = c;
	data->bytes_printed++;
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

void	nbr_buffer(t_data *data, u_nibbles u_nibble)
{
	u_nibbles	u_temp;
	
	u_temp.u_int64 = 0;
	if (data->format.base < 2 || data->format.base > 16)
		return ;
	if (data->format.is_negative && !(data->format.is_converted))
	{
		u_nibble.int64 = -(u_nibble.int64);
		data->format.is_converted = true;
		nbr_buffer(data, u_nibble);
	}
	else if (u_nibble.u_int64 < data->format.base)
	{
		if (data->format.upper_case)
			data->format.temp_buffer[data->format.nbr_len++] = UPPER_HEX[u_nibble.u_int64];
		else
			data->format.temp_buffer[data->format.nbr_len++] = LOWER_HEX[u_nibble.u_int64];
	}
	else
	{
		u_temp.u_int64 = u_nibble.u_int64 / data->format.base;
		nbr_buffer(data, u_temp);
		u_temp.u_int64 = u_nibble.u_int64 % data->format.base;
		nbr_buffer(data, u_temp);
	}
}
