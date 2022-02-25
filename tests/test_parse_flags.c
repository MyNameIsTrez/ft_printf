/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:43:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_flags)
{
	{
		const char *format = "#0- +42d";
		t_options	options;

		parse_flags(&format, &options);

		massert(options.flags.alternate, (bool)true);
		massert(options.flags.zero_fill, (bool)true);
		massert(options.flags.pad_right, (bool)true);
		massert(options.flags.plus_space, (bool)true);
		massert(options.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
