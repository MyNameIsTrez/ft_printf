/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_parse_argument.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:21:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 17:48:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

ssize_t	pft_parse_argument(t_options *options, va_list arg_ptr)
{
	t_base_and_prefix_fn const static	options_table[] = {
	['c'] = pft_get_char,
	['s'] = pft_get_string,
	['p'] = pft_get_pointer,
	['d'] = pft_get_decimal,
	['i'] = pft_get_decimal,
	['u'] = pft_get_unsigned,
	['x'] = pft_get_hex_lower,
	['X'] = pft_get_hex_upper,
	['%'] = pft_get_percent,
	};

	return (options_table[options->type](arg_ptr, options));
}

////////////////////////////////////////////////////////////////////////////////
