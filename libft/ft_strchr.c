/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Teghjyot <tesingh@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:37:18 by Teghjyot          #+#    #+#             */
/*   Updated: 2024/03/06 15:37:19 by Teghjyot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char		*ptr;
	unsigned char	uc;

	ptr = s;
	uc = (unsigned char)c;
	while (*ptr || *ptr == uc)
	{
		if (*ptr == uc)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
