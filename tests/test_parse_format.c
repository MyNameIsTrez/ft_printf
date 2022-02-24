/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 19:43:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static t_conversion	foo(const char	**format, ...)
{
	t_conversion	conversion;

	parse_format(format, &conversion);
	return (conversion);
}

Test(parse_format)
{
	{
		const char	*format = "#0- +42d";
		t_conversion	conversion = foo(&format, 1337);

		massert(conversion.options.flags.alternate, (bool)true);
		massert(conversion.options.flags.zero_fill, (bool)false);
		massert(conversion.options.flags.pad_right, (bool)true);
		massert(conversion.options.flags.plus_space, (bool)true);
		massert(conversion.options.flags.plus_sign, (bool)true);

		massert(conversion.options.field_width, (size_t)42);
		massert(conversion.options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "42d";
		t_conversion	conversion = foo(&format, 1337);

		massert(conversion.options.flags.alternate, (bool)false);
		massert(conversion.options.flags.zero_fill, (bool)false);
		massert(conversion.options.flags.pad_right, (bool)false);
		massert(conversion.options.flags.plus_space, (bool)false);
		massert(conversion.options.flags.plus_sign, (bool)false);

		massert(conversion.options.field_width, (size_t)42);
		massert(conversion.options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "d";
		t_conversion	conversion = foo(&format, 1337);

		massert(conversion.options.flags.alternate, (bool)false);
		massert(conversion.options.flags.zero_fill, (bool)false);
		massert(conversion.options.flags.pad_right, (bool)false);
		massert(conversion.options.flags.plus_space, (bool)false);
		massert(conversion.options.flags.plus_sign, (bool)false);

		massert(conversion.options.field_width, (size_t)0);
		massert(conversion.options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "0d";
		t_conversion	conversion = foo(&format, 1337);

		massert(conversion.options.flags.alternate, (bool)false);
		massert(conversion.options.flags.zero_fill, (bool)true);
		massert(conversion.options.flags.pad_right, (bool)false);
		massert(conversion.options.flags.plus_space, (bool)false);
		massert(conversion.options.flags.plus_sign, (bool)false);

		massert(conversion.options.field_width, (size_t)0);
		massert(conversion.options.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
