/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_argument.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 17:59:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	foo(char *prefix, char *expected, const char *format, ...)
{
	t_conversion	conversion;
	va_list	arg_ptr;

	initialize_state(&conversion);
	parse_conversion_type(&format, &conversion);
	fix_priorities(&conversion);

	va_start(arg_ptr, format);
	parse_argument(&conversion, arg_ptr);
	va_end(arg_ptr);

	massert(conversion.options.parts.base_str, expected);
	massert(conversion.options.parts.prefix, prefix);
}

Test(parse_argument)
{
	foo("", "a", "c", 'a');
	foo("", "42", "d", 42);
	foo("-", "42", "d", -42);
	foo("-", "2147483648", "d", -2147483648);
	foo("", "42a", "x", 0x42a);
	foo("", "42A", "X", 0x42a);
	foo("", "%", "%");
	foo("0x", "42a", "p", (void *)0x42a);
	foo("", "foo", "s", "foo\0bar");
	foo("", "42", "u", 42);
}

////////////////////////////////////////////////////////////////////////////////
