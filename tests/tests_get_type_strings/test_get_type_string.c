/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 17:59:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_type_string(t_conversion_function get_type_string,
								char *prefix, char *expected, ...)
{
	t_conversion	conversion;
	va_list	arg_ptr;

	initialize_state(&conversion);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &conversion);
	massert(conversion.options.parts.base_str, expected);
	free(conversion.options.parts.base_str);
	massert(conversion.options.parts.prefix, prefix);
	free(conversion.options.parts.prefix);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
