/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 01:50:00 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/01 20:51:06 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	render_data(t_data *data)
{
	char		specifier;
	t_nibbles	u_nibble;

	specifier = data->format.specifier;
	if ('%' == specifier)
		char_unpack(data, 37);
	else if ('c' == specifier)
		char_unpack(data, va_arg(data->ap, int));
	else if ('s' == specifier)
		str_unpack(data, va_arg(data->ap, char *));
	else if (ft_strchr("pdiuxX", specifier))
	{
		if (ft_strchr("di", specifier))
		{
			u_nibble.int64 = (long)va_arg(data->ap, int);
			data->format.is_signed = TRUE;
			if (u_nibble.int64 < 0)
				data->format.is_negative = TRUE;
		}
		else if (ft_strchr("uxX", specifier))
			u_nibble.u_int64 = va_arg(data->ap, unsigned int);
		else
			u_nibble.u_int64 = (unsigned long)va_arg(data->ap, void *);
		nbr_unpack(data, u_nibble);
	}
}
