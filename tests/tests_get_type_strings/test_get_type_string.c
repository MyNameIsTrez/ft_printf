/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:26:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_type_string(t_conversion_function get_type_string,
								char *expected, ...)
{
	t_conversion	conversion;
	va_list	arg_ptr;

	initialize_state(&conversion);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &conversion);
	char *v = conversion.conversion_str;
	massert(v, expected);
	free(v);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
