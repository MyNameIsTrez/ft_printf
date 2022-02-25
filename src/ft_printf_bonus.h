/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:22 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 17:38:46 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

////////////////////////////////////////////////////////////////////////////////

# include "get_type_strings.h"

////////////////////////////////////////////////////////////////////////////////

# include "../../libft/libft.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdbool.h>	// bool
# include <sys/types.h>	// ssize_t

////////////////////////////////////////////////////////////////////////////////

# define FLAGS " -+#0"
# define CONVERSION_TYPES "cspdiuxX%"
# define PRECISION_TYPES "pdiuxX"
# define ZERO_PAD_TYPES "pdiuxX%"

////////////////////////////////////////////////////////////////////////////////

typedef void	(*t_conversion_function)(va_list arg_ptr,
	t_conversion *conversion);

////////////////////////////////////////////////////////////////////////////////

typedef struct s_flags
{
	bool	alternate;
	bool	zero_fill;
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

typedef struct s_conversion
{
	t_options	options;
	char		*base_str;
	char		*prefix;
}	t_conversion;

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
int	ft_printf(const char *format, ...);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
