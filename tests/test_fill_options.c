/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fill_options.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/14 15:41:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

t_options	bar(const char	**format, ...)
{
	t_options	options;
	va_list		arg_ptr;

	va_start(arg_ptr, format);
	fill_options(format, &options, arg_ptr);
	va_end(arg_ptr);

	return (options);
}

Test(fill_options)
{
	{
		const char	*format = "#0- +42d";
		t_options	options = bar(&format, 1337);

		ASSERT(options.flags.alternate, (bool)true);
		ASSERT(options.flags.zero_fill, (bool)true);
		ASSERT(options.flags.aligned_left, (bool)true);
		ASSERT(options.flags.plus_space, (bool)true);
		ASSERT(options.flags.plus_sign, (bool)true);

		ASSERT(options.field_width, 42);
		ASSERT(options.precision, -1);
		ASSERT(*format, (char)'d');
		ASSERT(options.conversion_str, "1337");
	}

	{
		const char	*format = "42d";
		t_options	options = bar(&format, 1337);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)false);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 42);
		ASSERT(options.precision, -1);
		ASSERT(*format, (char)'d');
		ASSERT(options.conversion_str, "1337");
	}

	{
		const char	*format = "d";
		t_options	options = bar(&format, 1337);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)false);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 0);
		ASSERT(options.precision, -1);
		ASSERT(*format, (char)'d');
		ASSERT(options.conversion_str, "1337");
	}

	{
		const char	*format = "0d";
		t_options	options = bar(&format, 1337);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)true);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 0);
		ASSERT(options.precision, -1);
		ASSERT(*format, (char)'d');
		ASSERT(options.conversion_str, "1337");
	}
}

////////////////////////////////////////////////////////////////////////////////
