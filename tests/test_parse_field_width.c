/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_field_width.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/28 13:25:46 by sbos          ########   odam.nl         */
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

		ASSERT_INT(options.field_width, 42);
	}

	{
		const char *format = "d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT_INT(options.field_width, 0);
	}

	{
		const char *format = "0d";
		t_options	options;

		initialize_options(&options);
		parse_field_width(&format, &options);

		ASSERT_INT(options.field_width, 0);
	}
}

////////////////////////////////////////////////////////////////////////////////
