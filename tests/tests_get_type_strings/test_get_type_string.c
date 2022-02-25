/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_type_string.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 12:44:11 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:51:26 by sbos          ########   odam.nl         */
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
	free(options.parts.base_str);
	massert(options.parts.prefix, prefix);
	free(options.parts.prefix);
	va_end(arg_ptr);
}

////////////////////////////////////////////////////////////////////////////////
