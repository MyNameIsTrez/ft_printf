/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_argument.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:56:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	foo(bool expected_negative, char *prefix, char *expected, const char *format, ...)
{
	t_conversion	conversion;
	va_list	arg_ptr;

	initialize_state(&conversion);
	parse_conversion_type(&format, &conversion);
	fix_priorities(&conversion);

	va_start(arg_ptr, format);
	parse_argument(&conversion, arg_ptr);
	va_end(arg_ptr);

	massert(conversion.options.negative, expected_negative);
	massert(conversion.base_str, expected);
	massert(conversion.prefix, prefix);
}

Test(parse_argument)
{
	foo(false, "", "a", "c", 'a');
	foo(false, "", "42", "d", 42);
	foo(true, "-", "42", "d", -42);
	foo(true, "-", "2147483648", "d", -2147483648);
	foo(false, "", "42a", "x", 0x42a);
	foo(false, "", "42A", "X", 0x42a);
	foo(false, "", "%", "%");
	foo(false, "0x", "42a", "p", (void *)0x42a);
	foo(false, "", "foo", "s", "foo\0bar");
	foo(false, "", "42", "u", 42);
}

////////////////////////////////////////////////////////////////////////////////
