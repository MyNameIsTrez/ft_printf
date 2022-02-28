/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/28 14:21:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_type_string(t_base_and_prefix_fn get_type_string,
								char *prefix, char *expected, ...)
{
	t_options	options;
	va_list	arg_ptr;

	initialize_options(&options);
	va_start(arg_ptr, expected);
	get_type_string(arg_ptr, &options);
	massert(options.parts.base_str, expected);
	massert(options.parts.prefix, prefix);
	free_parts(&options.parts);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
