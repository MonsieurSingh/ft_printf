/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teghjyot <tesingh@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:36:39 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/03/06 15:36:40 by Teghjyot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;

	ptr = s;
	uc = (unsigned char)c;
	while (*ptr)
		ptr++;
	while (ptr != s)
	{
		if (*ptr == uc)
			return ((char *)ptr);
		ptr--;
	}
	if (*ptr == uc)
		return ((char *)ptr);
	return (NULL);
}
