//
//  parser.c
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#include "printf.h"

static void	parse_flags(t_data *data)
{
	char	flag;
	while (ft_strchr(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('-' == flag)
			data->format.has_minus = true;
		else if ('+' == flag)
			data->format.has_plus = true;
		else if (' ' == flag)
			data->format.has_space = true;
		else if ('#' == flag)
			data->format.has_hash = true;
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
	*value = atoi(data->s);
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
				data->format.upper_case = true;
		}
	}
	return (OK);
}
