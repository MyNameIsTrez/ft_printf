/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_argument.c                              :+:    :+:            */
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

void	foo(bool expected_negative, char *expected, const char *format, ...)
{
	t_state	state;
	va_list	arg_ptr;

	initialize_state(&state);
	parse_conversion_type(&format, &state);
	fix_priorities(&state);

	va_start(arg_ptr, format);
	parse_argument(&state, arg_ptr);
	va_end(arg_ptr);

	massert(state.negative, expected_negative);
	massert(state.conversion_str, expected);
}

Test(parse_argument)
{
	foo(false, "a", "c", 'a');
	foo(false, "42", "d", 42);
	foo(true, "42", "d", -42);
	foo(true, "2147483648", "d", -2147483648);
	foo(false, "42a", "x", 0x42a);
	foo(false, "42A", "X", 0x42a);
	foo(false, "%", "%");
	foo(false, "0x42a", "p", (void *)0x42a);
	foo(false, "foo", "s", "foo\0bar");
	foo(false, "42", "u", 42);
}

////////////////////////////////////////////////////////////////////////////////
