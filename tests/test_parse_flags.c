/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
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

Test(parse_flags)
{
	{
		const char *format = "#0- +42d";
		t_state	state;

		parse_flags(&format, &state);

		ASSERT(state.flags.alternate, (bool)true);
		ASSERT(state.flags.zero_fill, (bool)true);
		ASSERT(state.flags.aligned_left, (bool)true);
		ASSERT(state.flags.plus_space, (bool)true);
		ASSERT(state.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
