/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_parse_format.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:12:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 18:32:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	parse_options_type(const char **format, t_options *options)
{
	options->type = (unsigned char)**format;
}

STATIC void	parse_precision(const char **format, t_options *options)
{
	if (**format == '.')
	{
		options->precision = 0;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		options->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

STATIC void	parse_field_width(const char **format, t_options *options)
{
	options->field_width = (size_t)ft_atoi(*format);
	if (options->field_width != 0)
		(*format) += ft_get_digit_count((intmax_t)options->field_width);
}

STATIC void	parse_flags(const char **format, t_options *options)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			options->flags.alternate = true;
		else if (**format == '0')
			options->flags.zero_pad = true;
		else if (**format == '-')
			options->flags.pad_right = true;
		else if (**format == ' ')
			options->flags.plus_space = true;
		else if (**format == '+')
			options->flags.plus_sign = true;
		(*format)++;
	}
}

void	pft_parse_format(const char **format, t_options *options)
{
	pft_initialize_options(options);
	parse_flags(format, options);
	parse_field_width(format, options);
	parse_precision(format, options);
	parse_options_type(format, options);
	pft_fix_priorities(options);
}

////////////////////////////////////////////////////////////////////////////////
