/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_argument.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:21:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 17:22:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	parse_argument(t_options *options, va_list arg_ptr)
{
	const static t_base_and_prefix_fn	options_table[] = {
	['c'] = get_char,
	['s'] = get_string,
	['p'] = get_pointer,
	['d'] = get_decimal,
	['i'] = get_decimal,
	['u'] = get_unsigned,
	['x'] = get_hex_lower,
	['X'] = get_hex_upper,
	['%'] = get_percent,
	};

	options_table[options->type](arg_ptr, options);
}

////////////////////////////////////////////////////////////////////////////////
