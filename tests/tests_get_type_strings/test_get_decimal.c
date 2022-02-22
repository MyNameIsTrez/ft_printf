/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_decimal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/22 15:40:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	foo(bool expected_negative, t_conversion_function get_type_string,
					char *expected, ...)
{
	t_state	state;
	va_list	arg_ptr;

	initialize_state(&state);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &state);
	char *v = state.conversion_str;
	massert(state.negative, expected_negative);
	massert(v, expected);
	free(v);
	va_end(arg_ptr);
}

Test(get_decimal)
{
	foo(false, get_decimal, "42", 42);
	foo(true, get_decimal, "42", -42);
	foo(true, get_decimal, "2147483648", -2147483648);
}

////////////////////////////////////////////////////////////////////////////////
