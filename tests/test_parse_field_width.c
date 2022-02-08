/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_field_width.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/08 17:21:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_parse_field_width(void)
{
	{
		const char *format = "42d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT(options.field_width, 42);
	}

	{
		const char *format = "d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT(options.field_width, 0);
	}

	{
		const char *format = "0d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT(options.field_width, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////
