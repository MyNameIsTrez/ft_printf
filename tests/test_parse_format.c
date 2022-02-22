/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/22 15:40:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

static t_state	foo(const char	**format, ...)
{
	t_state	state;

	parse_format(format, &state);
	return (state);
}

Test(parse_format)
{
	{
		const char	*format = "#0- +42d";
		t_state	state = foo(&format, 1337);

		massert(state.flags.alternate, (bool)true);
		massert(state.flags.zero_fill, (bool)true);
		massert(state.flags.aligned_left, (bool)true);
		massert(state.flags.plus_space, (bool)true);
		massert(state.flags.plus_sign, (bool)true);

		massert(state.field_width, (size_t)42);
		massert(state.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "42d";
		t_state	state = foo(&format, 1337);

		massert(state.flags.alternate, (bool)false);
		massert(state.flags.zero_fill, (bool)false);
		massert(state.flags.aligned_left, (bool)false);
		massert(state.flags.plus_space, (bool)false);
		massert(state.flags.plus_sign, (bool)false);

		massert(state.field_width, (size_t)42);
		massert(state.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "d";
		t_state	state = foo(&format, 1337);

		massert(state.flags.alternate, (bool)false);
		massert(state.flags.zero_fill, (bool)false);
		massert(state.flags.aligned_left, (bool)false);
		massert(state.flags.plus_space, (bool)false);
		massert(state.flags.plus_sign, (bool)false);

		massert(state.field_width, (size_t)0);
		massert(state.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}

	{
		const char	*format = "0d";
		t_state	state = foo(&format, 1337);

		massert(state.flags.alternate, (bool)false);
		massert(state.flags.zero_fill, (bool)true);
		massert(state.flags.aligned_left, (bool)false);
		massert(state.flags.plus_space, (bool)false);
		massert(state.flags.plus_sign, (bool)false);

		massert(state.field_width, (size_t)0);
		massert(state.precision, (ssize_t)-1);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
