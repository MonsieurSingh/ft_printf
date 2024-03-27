//
//  render.c
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#include "printf.h"

int	render_data(t_data *data)
{
	u_nibbles	u_nibble;

	char	specifier = data->format.specifier;
	if ('%' == specifier)
		char_buffer('%', 1, data);
	else if ('c' == specifier)
		char_unpack(data, va_arg(data->ap, int));
	else if ('s' == specifier)
		str_unpack(data, va_arg(data->ap, char *));
	else if (ft_strchr("pdiuxX", specifier))
	{
		if (ft_strchr("di", specifier))
		{
			u_nibble.int64 = (long)va_arg(data->ap, int);
			data->format.is_signed = true;
			if (u_nibble.int64 < 0)
				data->format.is_negative = true;
		}
		else if (ft_strchr("uxX", specifier))
			u_nibble.u_int64 = va_arg(data->ap, unsigned int);
		else
			u_nibble.u_int64 = (unsigned long)va_arg(data->ap, void *);
		nbr_unpack(data, u_nibble);
	}
	return (OK);
}
