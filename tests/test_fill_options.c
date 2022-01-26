/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   UNUSED_test_fill_options.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 12:15:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_fill_options(void)
{
	t_options	options;
	const char	*format = "#0- +42d";

	fill_options(&format, &options);

	ASSERT_BOOL(options.flags.alternate, true);
	ASSERT_BOOL(options.flags.zero_fill, true);
	ASSERT_BOOL(options.flags.aligned_left, true);
	ASSERT_BOOL(options.flags.plus_space, true);
	ASSERT_BOOL(options.flags.plus_sign, true);

	ASSERT_INT(options.field_width, 0);
	ASSERT_INT(options.precision, -1);
}

////////////////////////////////////////////////////////////////////////////////
