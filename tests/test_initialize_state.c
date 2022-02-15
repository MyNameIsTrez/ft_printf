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

		ASSERT(state.flags.alternate, (bool)false);
		ASSERT(state.flags.zero_fill, (bool)false);
		ASSERT(state.flags.aligned_left, (bool)false);
		ASSERT(state.flags.plus_space, (bool)false);
		ASSERT(state.flags.plus_sign, (bool)false);

		ASSERT(state.field_width, (size_t)0);
		ASSERT(state.precision, (ssize_t)-1);
	}
}

////////////////////////////////////////////////////////////////////////////////
