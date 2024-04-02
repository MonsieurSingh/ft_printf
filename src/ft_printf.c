/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:50:22 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/02 03:54:02 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	render_data(va_list ap, const char *str)
{
	char		specifier;
	size_t		i;

	i = 0;
	specifier = *str;
	if ('%' == specifier)
		i += write(1, "%", 1);
	else if ('c' == specifier)
		i += ft_putchar_fd(va_arg(ap, int), 1);
	else if ('s' == specifier)
		i += ft_putstr_fd(va_arg(ap, char *), 1);
	else if ('d' == specifier || 'i' == specifier)
		i += ft_putnbr_fd(va_arg(ap, int), 1);
	else if ('u' == specifier)
		i += ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789", 1);
	else if ('x' == specifier)
		i += ft_putnbr_base_fd(va_arg(ap, unsigned int), LOWER_HEX, 1);
	else if ('X' == specifier)
		i += ft_putnbr_base_fd(va_arg(ap, unsigned int), UPPER_HEX, 1);
	else if ('p' == specifier)
	{
		i += ft_putstr_fd("0x", 1);
		i += ft_putnbr_base_fd((unsigned long)va_arg(ap, void *), LOWER_HEX, 1);
	}
	return ((int)i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, str);
	while (*str)
	{
		if ('%' == *str && *(++str))
		{
			ret += render_data(ap, str);
		}
		else
		{
			write(1, &*str, 1);
			ret++;
		}
		str++;
	}
	va_end(ap);
	return (ret);
}
