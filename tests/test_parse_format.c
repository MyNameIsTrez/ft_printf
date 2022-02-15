/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_format.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 12:33:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

t_state	bar(const char	**format, ...)
{
	t_state	state;
	va_list		arg_ptr;

	va_start(arg_ptr, format);
	parse_format(format, &state, arg_ptr);
	va_end(arg_ptr);

	return (state);
}

Test(parse_format)
{
	{
		const char	*format = "#0- +42d";
		t_state	state = bar(&format, 1337);

		ASSERT(state.flags.alternate, (bool)true);
		ASSERT(state.flags.zero_fill, (bool)true);
		ASSERT(state.flags.aligned_left, (bool)true);
		ASSERT(state.flags.plus_space, (bool)true);
		ASSERT(state.flags.plus_sign, (bool)true);

		ASSERT(state.field_width, 42);
		ASSERT(state.precision, -1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "42d";
		t_state	state = bar(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)false);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, 42);
		ASSERT(state.precision, -1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "d";
		t_state	state = bar(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)false);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, 0);
		ASSERT(state.precision, -1);
		ASSERT(*format, (char)'d');
	}

	{
		const char	*format = "0d";
		t_state	state = bar(&format, 1337);

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)true);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, 0);
		ASSERT(state.precision, -1);
		ASSERT(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
