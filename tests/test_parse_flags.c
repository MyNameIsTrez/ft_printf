/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 12:48:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_parse_flags(void)
{
	{
		const char *format = "#0- +42d";
		t_options	options;

		parse_flags(&format, &options);

		ASSERT_BOOL(options.flags.alternate, true);
		ASSERT_BOOL(options.flags.zero_fill, true);
		ASSERT_BOOL(options.flags.aligned_left, true);
		ASSERT_BOOL(options.flags.plus_space, true);
		ASSERT_BOOL(options.flags.plus_sign, true);
	}

	{

	}
}

////////////////////////////////////////////////////////////////////////////////
