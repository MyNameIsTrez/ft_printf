/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2_pft_parse_format.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:12:45 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/25 17:13:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	pft_parse_options_type(char **format, unsigned char *type)
{
	*type = (unsigned char)**format;
}

STATIC void	pft_parse_precision(char **format, ssize_t *precision)
{
	if (**format == '.')
	{
		*precision = 0;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		*precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

STATIC void	pft_parse_field_width(char **format, size_t *field_width)
{
	*field_width = (size_t)ft_atoi(*format);
	if (*field_width != 0)
		(*format) += ft_get_digit_count((intmax_t)(*field_width));
}

STATIC void	pft_parse_flags(char **format, t_flags *flags)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			flags->alternate = true;
		else if (**format == '0')
			flags->zero_pad = true;
		else if (**format == '-')
			flags->pad_right = true;
		else if (**format == ' ')
			flags->plus_space = true;
		else if (**format == '+')
			flags->plus_sign = true;
		(*format)++;
	}
}

void	pft_parse_format(char **format, t_options *options)
{
	pft_parse_flags(format, &options->flags);
	pft_parse_field_width(format, &options->field_width);
	pft_parse_precision(format, &options->precision);
	pft_parse_options_type(format, &options->type);
	pft_fix_priorities(options);
}

////////////////////////////////////////////////////////////////////////////////
