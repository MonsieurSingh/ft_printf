/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:58:38 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/02 03:11:21 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef UPPER_HEX
#  define UPPER_HEX "0123456789ABCDEF"
# endif

# ifndef LOWER_HEX
#  define LOWER_HEX "0123456789abcdef"
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *str, ...);

#endif
