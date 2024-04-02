/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teghjyot <tesingh@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:37:37 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/03/06 15:37:38 by Teghjyot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = dst;
	src_ptr = src;
	while (n-- > 0)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}
