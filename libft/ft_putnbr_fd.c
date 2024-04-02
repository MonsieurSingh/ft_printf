/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:37:25 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/04/02 02:32:40 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(long long n, int fd)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (!(n < 10))
	{
		i += ft_putnbr_fd((int)(n / 10), fd);
		n %= 10;
	}
	if (n < 10)
		i += ft_putchar_fd(n + 48, fd);
	return (i);
}
