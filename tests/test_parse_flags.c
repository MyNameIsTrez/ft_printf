/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
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

Test(parse_flags)
{
	{
		const char *format = "#0- +42d";
		t_state	state;

		parse_flags(&format, &state);

		massert(state.flags.alternate, (bool)true);
		massert(state.flags.zero_fill, (bool)true);
		massert(state.flags.aligned_left, (bool)true);
		massert(state.flags.plus_space, (bool)true);
		massert(state.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
