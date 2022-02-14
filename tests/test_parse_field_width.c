/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_field_width.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/14 15:10:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_field_width)
{
	{
		const char *format = "42d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT(options.field_width, 42);
		ASSERT(*format, (char)'d');
	}

	{
		const char *format = "d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT(options.field_width, 0);
		ASSERT(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
