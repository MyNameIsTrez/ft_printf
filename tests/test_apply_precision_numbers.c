/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_apply_precision_numbers.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 12:18:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:23:47 by sbos          ########   odam.nl         */
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
			apply_precision_numbers(&conversion);
		}
		va_end(arg_ptr);
		massert(conversion.base_str, expected);
	}
}

////////////////////////////////////////////////////////////////////////////////

Test(apply_precision_numbers)
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
