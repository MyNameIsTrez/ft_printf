/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/08 17:24:14 by sbos          ########   odam.nl         */
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

		ASSERT(options.flags.alternate, (bool)true);
		ASSERT(options.flags.zero_fill, (bool)true);
		ASSERT(options.flags.aligned_left, (bool)true);
		ASSERT(options.flags.plus_space, (bool)true);
		ASSERT(options.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
