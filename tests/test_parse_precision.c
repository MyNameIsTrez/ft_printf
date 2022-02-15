/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_precision.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 16:05:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

/*
An optional precision, in the form of a period . followed by an optional digit string.
If the digit string is omitted, the precision is taken as zero.
This gives the minimum number of digits to appear for d, i, o, u, x, and X conversions,
the number of digits to appear after the decimal-point for a, A, e, E, f, and F conversions,
the maximum number of significant digits for g and G con-versions,
or the maximum number of characters to be printed from a string for s conversions.
*/
Test(parse_precision)
{
	{
		const char *format = ".42d";
		t_state	state;

		initialize_state(&state);
		parse_precision(&format, &state);

		// printf("'%7.42d'\n",  0) -> '000000000000000000000000000000000000000000'
		// printf("'%7.42d'\n", 42) -> '000000000000000000000000000000000000000042'
		ASSERT(state.precision, 42);
		ASSERT(*format, (char)'d')
	}

	{
		const char *format = ".1d";
		t_state	state;

		initialize_state(&state);
		parse_precision(&format, &state);

		// printf("%.1d",  0) -> '0'
		// printf("%.1d", 42) -> '42'
		ASSERT(state.precision, 1); // TODO: What should this be??
		ASSERT(*format, (char)'d')
	}

	{
		const char *format = ".0d";
		t_state	state;

		initialize_state(&state);
		parse_precision(&format, &state);

		// printf("%.0d",  0) -> ''
		// printf("%.0d", 42) -> '42'
		ASSERT(state.precision, 0); // TODO: What should this be??
		ASSERT(*format, (char)'d')
	}

	{
		const char *format = ".d";
		t_state	state;

		initialize_state(&state);
		parse_precision(&format, &state);

		// printf("%.d",  0) -> ''
		// printf("%.d", 42) -> '42'
		ASSERT(state.precision, 0); // TODO: What should this be??
		ASSERT(*format, (char)'d')
	}

	{
		const char *format = "d";
		t_state	state;

		initialize_state(&state);
		parse_precision(&format, &state);

		// printf("'%d'\n" , 0) -> '0'
		// printf("'%.0d'\n", 0) -> ''
		ASSERT(state.precision, -1);
		ASSERT(*format, (char)'d')
	}
}

////////////////////////////////////////////////////////////////////////////////
