/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teghjyot <tesingh@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:38:20 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/03/06 15:38:20 by Teghjyot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_overflow(long long a, long long b)
{
	long double	result;

	if (a < 0 && b < 0)
		return (1);
	result = a * b;
	if (a == 0 || b == 0 || a == result / b)
		return (0);
	else
		return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (is_overflow(count, size))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if ((count < 0 && size < 0))
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
