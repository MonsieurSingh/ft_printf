/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:37:28 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/04/02 00:50:13 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	i += ft_putstr_fd(s, fd);
	i += write(fd, (char []){10}, sizeof(char));
	return (i);
}
