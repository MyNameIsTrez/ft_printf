/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/01 18:07:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_char_helper(t_options *options, const char *format, ...)
{
	va_list	arg_ptr;

	(void)options;
	va_start(arg_ptr, format);
	ASSERT_STR(get_char(options, &arg_ptr), "x");
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////

void	test_get_char(void)
{
	{
		t_options	options;

		initialize_options(&options);
		test_get_char_helper(&options, "", 42, 'x');
	}
}

////////////////////////////////////////////////////////////////////////////////
