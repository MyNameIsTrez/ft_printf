/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_initialize_options.c                          :+:    :+:            */
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

Test(initialize_options)
{
	{
		t_options	options;

		initialize_options(&options);

		ASSERT(options.flags.alternate, (bool)false);
		ASSERT(options.flags.zero_fill, (bool)false);
		ASSERT(options.flags.aligned_left, (bool)false);
		ASSERT(options.flags.plus_space, (bool)false);
		ASSERT(options.flags.plus_sign, (bool)false);

		ASSERT(options.field_width, 0);
		ASSERT(options.precision, -1);
	}
}

////////////////////////////////////////////////////////////////////////////////
