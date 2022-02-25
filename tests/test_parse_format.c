/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:43:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static t_options	foo(const char	**format, ...)
{
	t_options	options;

	parse_format(format, &options);
	return (options);
}

Test(parse_format)
{
	{
		const char	*format = "#0- +42d";
		t_options	options = foo(&format, 1337);

		massert(options.flags.alternate, (bool)true);
		massert(options.flags.zero_fill, (bool)false);
		massert(options.flags.pad_right, (bool)true);
		massert(options.flags.plus_space, (bool)true);
		massert(options.flags.plus_sign, (bool)true);

		massert(options.field_width, (size_t)42);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "42d";
		t_options	options = foo(&format, 1337);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_fill, (bool)false);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)42);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "d";
		t_options	options = foo(&format, 1337);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_fill, (bool)false);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)0);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "0d";
		t_options	options = foo(&format, 1337);

		massert(options.flags.alternate, (bool)false);
		massert(options.flags.zero_fill, (bool)true);
		massert(options.flags.pad_right, (bool)false);
		massert(options.flags.plus_space, (bool)false);
		massert(options.flags.plus_sign, (bool)false);

		massert(options.field_width, (size_t)0);
		massert(options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
