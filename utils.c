//
//  utils.c
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#include "printf.h"

void	set_padding_zeros(t_data *data)
{
	if (data->format.precision >= 0)
	{
		if (data->format.precision >= data->format.nbr_len)
		{
			data->format.padding_zeros =
			data->format.precision - data->format.nbr_len;
			return ;
		}
	}
	if (data->format.zero_pad)
	{
		if (data->format.has_minus)
			return ;
		
		if (data->format.width > data->format.nbr_len)
			data->format.padding_zeros =
			data->format.width - data->format.nbr_len;
		
		if (data->format.specifier == 'u')
			return ;
		
		else if ((ft_strchr("xX", data->format.specifier) && data->format.has_hash
				  && (data->format.temp_buffer[0] != '0')) || (data->format.specifier == 'p'))
			data->format.padding_zeros -= 2; // because 0x pad
		
		else if (data->format.is_negative ||
				 (!data->format.is_negative &&
				  (data->format.has_plus || data->format.has_space)))
			data->format.padding_zeros--;
	}
	
	if (data->format.padding_zeros < 0)
		data->format.padding_zeros = 0;
}

void	set_padding_spaces(t_data *data)
{
	data->format.padding_spaces =
	data->format.width - data->format.padding_zeros - data->format.nbr_len;
	if (ft_strchr("uxXp", data->format.specifier))
	{
		if ((ft_strchr("xX", data->format.specifier) &&
			 data->format.has_hash && (data->format.temp_buffer[0] != '0')) ||
			(data->format.specifier == 'p'))
			data->format.padding_spaces -= 2;
		return ;
	}
	if (data->format.is_negative)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.has_plus)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.has_space)
	{
		data->format.padding_spaces--;
		return ;
	}
}

void	put_0x(t_data *data)
{
	if ((ft_strchr("xX", data->format.specifier) &&
		 (data->format.has_hash) &&
		 (data->format.temp_buffer[0] != '0')) ||
		(data->format.specifier == 'p'))
	{
		if (data->format.upper_case)
			str_buffer("0X", 2, data);
		else
			str_buffer("0x", 2, data);
		
	}
}

void	put_sign(t_data *data)
{
	
	if (data->format.base == BASE_16)
		put_0x(data);
	else if (data->format.is_signed)
	{
		if (data->format.is_negative)
			char_buffer('-', 1, data);
		else if (!data->format.is_negative)
		{
			if (data->format.has_plus)
				char_buffer('+', 1, data);
			else if (!data->format.has_plus &&
					 data->format.has_space)
				char_buffer(' ', 1, data);
		}
	}
}
