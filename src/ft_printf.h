/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 11:23:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

////////////////////////////////////////////////////////////////////////////////

# include "libft.h"

////////////////////////////////////////////////////////////////////////////////

# include "get_type_strings/get_type_strings.h"

////////////////////////////////////////////////////////////////////////////////

# ifndef STATIC
#  define STATIC static
# endif

////////////////////////////////////////////////////////////////////////////////

# define FLAGS				" -+#0"
# define PRECISION_TYPES	"pdiuxX"
# define ZERO_PAD_TYPES		"pdiuxX%"
# define FORMAT_TYPES		"cspdiuxX%"

////////////////////////////////////////////////////////////////////////////////

typedef t_status	(*t_base_and_prefix_fn)\
		(va_list arg_ptr, t_options *options);

////////////////////////////////////////////////////////////////////////////////

typedef struct s_flags
{
	bool	alternate;
	bool	zero_pad;
	bool	pad_right;
	bool	plus_space;
	bool	plus_sign;
}	t_flags;

typedef struct s_parts
{
	char	*left_pad;
	char	*prefix;
	char	*precision_or_zero_pad;
	char	*base_str;
	char	*right_pad;
}	t_parts;

typedef struct s_options
{
	t_flags	flags;
	t_parts	parts;
	size_t	field_width;
	ssize_t	precision;
	t_u8	type;
	size_t	len;
}	t_options;

////////////////////////////////////////////////////////////////////////////////

t_status	pft_fill_parts(t_options *options);
void		pft_fix_priorities(t_options *options);
void		pft_initialize_options(t_options *options);
t_status	pft_parse_argument(t_options *options, va_list arg_ptr);
void		pft_parse_format(char **format, t_options *options);

t_status	pft_accumulate(ssize_t ret, size_t *acc);
t_status	pft_putstr(char *str, size_t *acc);
t_status	pft_putchar(char chr, size_t *acc);
t_status	pft_put_substr(char *start, char *end, size_t *acc);
t_status	pft_free_parts(t_parts *parts);

////////////////////////////////////////////////////////////////////////////////

t_i32		ft_printf(const char *format, ...);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
