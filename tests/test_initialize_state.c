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
		t_conversion	conversion;

		initialize_state(&conversion);

		massert(conversion.options.flags.alternate, (bool)false);
		massert(conversion.options.flags.zero_fill, (bool)false);
		massert(conversion.options.flags.pad_right, (bool)false);
		massert(conversion.options.flags.plus_space, (bool)false);
		massert(conversion.options.flags.plus_sign, (bool)false);

		massert(conversion.options.field_width, (size_t)0);
		massert(conversion.options.precision, (ssize_t)-1);
	}
}

////////////////////////////////////////////////////////////////////////////////
