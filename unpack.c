//
//  unpack.c
//  ft_printf
//
//  Created by Devjyot Singh on 27/3/2024.
//

#include "printf.h"

void	unpack_width(t_data *data, char *s)
{
	int	l;

	l = (int)ft_strlen(s);
	if (data->format.width > 0)
	{
		if (data->format.precision >= 0)
		{
			if (data->format.precision > l)
				data->format.padding_spaces = data->format.width - l;
			else if (data->format.precision < l)
				data->format.padding_spaces =
				data->format.width - data->format.precision;
		}
		else
			data->format.padding_spaces = data->format.width - l;
	}
}

void	char_unpack(t_data *data, char c)
{
	int	width;
	
	width = data->format.width;
	if (width > 1)
	{
		if (data->format.has_minus)
		{
			char_buffer(c, 1, data);
			char_buffer(' ', width - 1, data);
		}
		else
		{
			char_buffer(' ', width - 1, data);
			char_buffer(c, 1, data);
		}
	}
	else
		char_buffer(c, 1, data);
}

void	str_unpack(t_data *data, char *s)
{
	if (NULL == s)
		s = "(null)";
	unpack_width(data, s);
	if (data->format.has_minus)
	{
		if (data->format.precision >= 0)
			str_buffer(s, data->format.precision, data);
		else
			str_buffer(s, (int)ft_strlen(s), data);
		char_buffer(' ', data->format.padding_spaces, data);
	}
	else
	{
		char_buffer(' ', data->format.padding_spaces, data);
		if (data->format.precision >= 0)
			str_buffer(s, data->format.precision, data);
		else
			str_buffer(s, (int)ft_strlen(s), data);
	}
}

void	nbr_unpack(t_data *data, u_nibbles u_nibble)
{
	nbr_buffer(data, u_nibble);
	set_padding_zeros(data);
	set_padding_spaces(data);
	if (data->format.has_minus)
	{
		put_sign(data);
		char_buffer('0', data->format.padding_zeros, data);
		str_buffer(data->format.temp_buffer, data->format.nbr_len, data);
		char_buffer(' ', data->format.padding_spaces, data);
	}
	else
	{
		char_buffer(' ', data->format.padding_spaces, data);
		put_sign(data);
		char_buffer('0', data->format.padding_zeros, data);
		str_buffer(data->format.temp_buffer, data->format.nbr_len, data);
	}
}
