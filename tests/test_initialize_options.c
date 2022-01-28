/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_initialize_options.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 12:48:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_initialize_options(void)
{
	{
		t_options	options;

		initialize_options(&options);

		ASSERT_BOOL(options.flags.alternate, false);
		ASSERT_BOOL(options.flags.zero_fill, false);
		ASSERT_BOOL(options.flags.aligned_left, false);
		ASSERT_BOOL(options.flags.plus_space, false);
		ASSERT_BOOL(options.flags.plus_sign, false);

		ASSERT_INT(options.field_width, 0);
		ASSERT_INT(options.precision, -1);
	}

	{

	}
}

////////////////////////////////////////////////////////////////////////////////
