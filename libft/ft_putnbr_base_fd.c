/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:37:25 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/04/02 03:00:52 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	char	c[99];
	int		index;
	size_t	base_len;

	base_len = ft_strlen(base);
	index = 0;
	if (nbr == 0)
	{
		ft_putchar_fd(base[0], fd);
		return (1);
	}
	while (nbr > 0)
	{
		c[index++] = base[(nbr % base_len)];
		nbr /= base_len;
	}
	base_len = index;
	while (index--)
		ft_putchar_fd(c[index], fd);
	return (base_len);
}
