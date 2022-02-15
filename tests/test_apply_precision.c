/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_apply_precision.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 16:57:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	foo(char *expected, const char *format, ...)
{
	{
		t_state	state;
		va_list	arg_ptr;

		va_start(arg_ptr, format);
		format++;
		parse_format(&format, &state);
		if (state.conversion_type != '%')
		{
			parse_argument(&state, arg_ptr);
			apply_precision(&state);
		}
		va_end(arg_ptr);
		ASSERT(state.conversion_str, expected);
	}
}

////////////////////////////////////////////////////////////////////////////////

Test(apply_precision)
{
	foo("123", "%.d", 123);
	foo("123", "%.0d", 123);
	foo("123", "%.1d", 123);
	foo("", "%.d", 0);
	foo("", "%.0d", 0);
	foo("0", "%.1d", 0);
	// foo("00123", "%.5d", 123);
}

////////////////////////////////////////////////////////////////////////////////
