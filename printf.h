//
//  printf.h
//  ft_printf
//
//  Created by Devjyot Singh on 23/3/2024.
//

#ifndef printf_h
# define printf_h

# ifndef bool
# define bool int
# endif

# ifndef false
# define false 0
# endif

# ifndef true
# define true 1
# endif

# ifndef BUFF_SIZE
# define BUFF_SIZE (1<<12)
# endif

# ifndef FLAGS
# define FLAGS "-+ 0#"
# endif

# ifndef SPECIFIERS
# define SPECIFIERS "cspdiuxX%"
# endif

# ifndef UPPER_HEX
# define UPPER_HEX "0123456789ABCDEF"
# endif

# ifndef LOWER_HEX
# define LOWER_HEX "0123456789abcdef"
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../ft/libft.h"

typedef unsigned char	byte;

typedef union
{
	unsigned long	u_int64;
	long			int64;
} u_nibbles;

typedef enum
{
	OK = 0,
	MALLOC_ERROR = -27,
	PARSE_ERROR  = -42,
} e_error;

typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10  = 10,
	BASE_16  = 16,
} e_base;

typedef struct s_format
{
	bool	has_minus;
	bool	has_plus;
	bool	has_space;
	bool	has_zero;
	bool	has_apostrophe;
	bool	has_hash;
	int		width;
	int		precision;
	//cspdiuxX%
	char	specifier;
	bool	upper_case;
	int		padding_spaces;
	bool	is_negative;
	bool	is_signed;
	bool	is_converted;
	char	temp_buffer[64];
	int		nbr_len;
	int		padding_zeros;
	int		zero_pad;
	e_base	base;
} t_format;

typedef struct data
{
	const char	*s;
	va_list		ap;
	int			bytes_printed;
	char		*buffer;
	int			buffer_index;
	t_format	format;
} t_data;

int		is_bool(void);
int		is_true(void);
int		ft_printf(const char *, ...);
int		parse_data(t_data *data);
void	write_buffer(t_data *data, char c);
int		render_data(t_data *data);
void	flush_buffer(t_data *data);
void	char_buffer(char c, int n, t_data *data);
void	char_unpack(t_data *data, char c);
void	str_buffer(char *s, int n, t_data *data);
void	str_unpack(t_data *data, char *s);
void	nbr_unpack(t_data *data, u_nibbles u_nibble);
void	unpack_width(t_data *data, char *s);
void	set_padding_zeros(t_data *data);
void	set_padding_spaces(t_data *data);
void	nbr_buffer(t_data *data, u_nibbles u_nibble);
void	put_sign(t_data *data);
void	put_0x(t_data *data);

#endif /* printf_h */
