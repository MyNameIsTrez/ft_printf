/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_initialize_state.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/10 12:43:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(initialize_state)
{
	{
		t_state	state;

		initialize_state(&state);

		massert(state.flags.alternate, (bool)false);
		massert(state.flags.zero_fill, (bool)false);
		massert(state.flags.aligned_left, (bool)false);
		massert(state.flags.plus_space, (bool)false);
		massert(state.flags.plus_sign, (bool)false);

		massert(state.field_width, (size_t)0);
		massert(state.precision, (ssize_t)-1);
	}
}

////////////////////////////////////////////////////////////////////////////////
