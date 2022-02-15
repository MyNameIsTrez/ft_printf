/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_argument.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 12:33:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	foo(char *expected, const char *format, ...)
{
	t_state	state;
	va_list		arg_ptr;

	initialize_state(&state);
	parse_conversion_type(&format, &state);
	fix_priorities(&state);

	va_start(arg_ptr, format);
	parse_argument(&state, arg_ptr);
	va_end(arg_ptr);

	ASSERT(state.conversion_str, expected);
}

Test(parse_argument)
{
	{
		foo("a", "c", 'a');
		foo("42", "d", 42);
		foo("42a", "x", 0x42a);
		foo("42A", "X", 0x42a);
		foo("%", "%");
		foo("0x42a", "p", (void *)0x42a);
		foo("foo", "s", "foo\0bar");
		foo("42", "u", 42);
	}
}

////////////////////////////////////////////////////////////////////////////////
