/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 12:33:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_type_string(t_conversion_function get_type_string,
								char *expected, ...)
{
	t_state	state;
	va_list		arg_ptr;

	initialize_state(&state);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &state);
	char *v = state.conversion_str;
	ASSERT(v, expected);
	free(v);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
