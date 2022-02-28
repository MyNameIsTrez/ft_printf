/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_decimal.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/28 14:33:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	foo(t_base_and_prefix_fn get_type_string,
					char *expected, ...)
{
	t_options	options;
	va_list	arg_ptr;

	initialize_options(&options);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &options);
	massert(options.parts.base_str, expected);
	free_parts(&options.parts);
	va_end(arg_ptr);
}

Test(get_decimal)
{
	foo(get_decimal, "42", 42);
	foo(get_decimal, "42", -42);
	foo(get_decimal, "2147483648", -2147483648);
}

////////////////////////////////////////////////////////////////////////////////
