/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 21:10:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

////////////////////////////////////////////////////////////////////////////////

# include "../libft/libft.h"

////////////////////////////////////////////////////////////////////////////////

# include "pft_get_type_strings.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdbool.h>	// bool
# include <sys/types.h>	// ssize_t

////////////////////////////////////////////////////////////////////////////////

# define STATIC //static

////////////////////////////////////////////////////////////////////////////////

# define FLAGS " -+#0"
# define PRECISION_TYPES "pdiuxX"
# define ZERO_PAD_TYPES "pdiuxX%"

////////////////////////////////////////////////////////////////////////////////

typedef t_success	(*t_base_and_prefix_fn)\
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
	t_flags			flags;
	t_parts			parts;
	size_t			field_width;
	ssize_t			precision;
	unsigned char	type;
	size_t			len;
}	t_options;

////////////////////////////////////////////////////////////////////////////////

t_success	pft_fill_parts(t_options *options);
void		pft_fix_priorities(t_options *options);
void		pft_initialize_options(t_options *options);
ssize_t		pft_parse_argument(t_options *options, va_list arg_ptr);
void		pft_parse_format(char **format, t_options *options);

ssize_t		pft_accumulate(ssize_t ret, size_t *acc);
ssize_t		pft_putstr(char *str, size_t *acc);
ssize_t		pft_putchr(char chr, size_t *acc);
ssize_t		pft_put_substr(char *start, char *end, size_t *acc);
void		pft_free_parts(t_parts *parts);

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief This is a recreation of printf() from libc.
 * It doesn’t implement the buffer management of the original printf().
 * It handles the following conversions: "cspdiuxX%" .
 * It handles any combination of the following flags: "-0."
 * and the field minimum width under all conversions.
 * It handles all the following flags: "# +" (yes, one of them is a space).
 *
 * @param format See "man 3 printf".
 *
 * @return If successful, returns the number of characters printed
 * (excluding the null terminator).
 * If an output error is encountered, a negative value is returned.
 */
int			ft_printf(const char *format, ...);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
