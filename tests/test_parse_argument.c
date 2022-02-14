/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_argument.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/14 14:46:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	foo(char *expected, const char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;

	fill_options(&format, &options);

	va_start(arg_ptr, format);
	parse_argument(&options, arg_ptr);
	va_end(arg_ptr);

	ASSERT(options.conversion_str, expected);
}

Test(parse_argument)
{
	{
		foo("42", "d", 42);
	}
}

////////////////////////////////////////////////////////////////////////////////
