/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fill_options.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/10 12:43:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(fill_options)
{
	{
		t_options	options;
		const char	*format = "#0- +42d";

		fill_options(&format, &options);

		ASSERT(options.flags.alternate, (bool)true);
		ASSERT(options.flags.zero_fill, (bool)true);
		ASSERT(options.flags.aligned_left, (bool)true);
		ASSERT(options.flags.plus_space, (bool)true);
		ASSERT(options.flags.plus_sign, (bool)true);

		ASSERT(options.field_width, 42);
		ASSERT(options.precision, -1);
	}

	{
		t_options	options;
		const char	*format = "42d";

		fill_options(&format, &options);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)false);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 42);
		ASSERT(options.precision, -1);
	}

	{
		t_options	options;
		const char	*format = "d";

		fill_options(&format, &options);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)false);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 0);
		ASSERT(options.precision, -1);
	}

	{
		t_options	options;
		const char	*format = "0d";

		fill_options(&format, &options);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)true);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 0);
		ASSERT(options.precision, -1);
	}
}

////////////////////////////////////////////////////////////////////////////////
