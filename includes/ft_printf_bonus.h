/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:09:26 by tesingh           #+#    #+#             */
/*   Updated: 2024/04/02 09:36:58 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

# ifndef FLAGS
#  define FLAGS "-+ 0#"
# endif

# ifndef SPECIFIERS
#  define SPECIFIERS "cspdiuxX%"
# endif

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

typedef int				t_bool;

typedef union u_nibbles
{
	unsigned long	u_int64;
	long			int64;
}	t_nibbles;

typedef enum e_error
{
	OK = 0,
	MALLOC_ERROR = -27,
	PARSE_ERROR = -42,
}	t_error;

typedef enum e_enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	t_base;

typedef struct s_format
{
	t_bool	has_minus;
	t_bool	has_plus;
	t_bool	has_space;
	t_bool	has_zero;
	t_bool	has_apostrophe;
	t_bool	has_hash;
	t_bool	upper_case;
	t_bool	is_negative;
	t_bool	is_signed;
	t_bool	is_converted;
	int		width;
	int		precision;
	int		padding_spaces;
	int		nbr_len;
	int		padding_zeros;
	char	temp_buffer[64];
	char	specifier;
	t_base	base;
}	t_format;

typedef struct data
{
	const char	*s;
	char		*buffer;
	int			bytes_printed;
	int			buffer_index;
	va_list		ap;
	t_format	format;
}	t_data;

int		ft_printf(const char *str, ...);
int		parse_data(t_data *data);
void	write_buffer(t_data *data, char c);
void	render_data(t_data *data);
void	flush_buffer(t_data *data);
void	char_buffer(char c, int n, t_data *data);
void	char_unpack(t_data *data, char c);
void	str_buffer(char *s, int n, t_data *data);
void	str_unpack(t_data *data, char *s);
void	nbr_unpack(t_data *data, t_nibbles u_nibble);
void	unpack_width(t_data *data, char *s);
void	set_padding_zeros(t_data *data);
void	set_padding_spaces(t_data *data);
void	nbr_buffer(t_data *data, t_nibbles u_nibble);
void	put_sign(t_data *data);
void	put_0x(t_data *data);

#endif
