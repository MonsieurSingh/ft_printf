/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:42:59 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/01 20:50:27 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	parse_flags(t_data *data)
{
	char	flag;

	while (ft_strchr(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('-' == flag)
			data->format.has_minus = TRUE;
		else if ('+' == flag)
			data->format.has_plus = TRUE;
		else if (' ' == flag)
			data->format.has_space = TRUE;
		else if ('#' == flag)
			data->format.has_hash = TRUE;
		else if ('0' == flag)
			data->format.has_zero = TRUE;
		data->s++;
	}
}

static void	get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		data->s++;
		return ;
	}
	*value = ft_atoi(data->s);
	while ((*data->s >= '0' && *data->s <= '9') && data->s)
		data->s++;
}

int	parse_data(t_data *data)
{
	ft_bzero(&data->format, sizeof(t_format));
	data->format.precision = -1;
	parse_flags(data);
	get_value(data, &data->format.width);
	if (*data->s == '.' && *(data->s++))
		get_value(data, &data->format.precision);
	if (!ft_strchr(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (ft_strchr("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (ft_strchr("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = TRUE;
		}
	}
	return (OK);
}
