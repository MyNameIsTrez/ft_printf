/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_apply_precision.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:27:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	foo(char *expected, const char *format, ...)
{
	{
		t_conversion	conversion;
		va_list	arg_ptr;

		va_start(arg_ptr, format);
		format++;
		parse_format(&format, &conversion);
		if (conversion.options.type != '%')
		{
			parse_argument(&conversion, arg_ptr);
			apply_precision(&conversion);
		}
		va_end(arg_ptr);
		massert(conversion.conversion_str, expected);
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
