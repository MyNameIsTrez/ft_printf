/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 17:54:53 by sbos          ########   odam.nl         */
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

		ASSERT(state.flags.alternate, (bool)true);
		ASSERT(state.flags.zero_fill, (bool)true);
		ASSERT(state.flags.aligned_left, (bool)true);
		ASSERT(state.flags.plus_space, (bool)true);
		ASSERT(state.flags.plus_sign, (bool)true);

		ASSERT(state.field_width, (size_t)42);
		ASSERT(state.precision, (ssize_t)-1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "42d";
		t_state	state = foo(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)false);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, (size_t)42);
		ASSERT(state.precision, (ssize_t)-1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "d";
		t_state	state = foo(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)false);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, (size_t)0);
		ASSERT(state.precision, (ssize_t)-1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "0d";
		t_state	state = foo(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)true);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, (size_t)0);
		ASSERT(state.precision, (ssize_t)-1);
		ASSERT(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
