/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_flags.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 18:07:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_flags)
{
	{
		const char *format = "#0- +42d";
		t_conversion	conversion;

		parse_flags(&format, &conversion);

		massert(conversion.options.flags.alternate, (bool)true);
		massert(conversion.options.flags.zero_fill, (bool)true);
		massert(conversion.options.flags.pad_right, (bool)true);
		massert(conversion.options.flags.plus_space, (bool)true);
		massert(conversion.options.flags.plus_sign, (bool)true);
	}
}

////////////////////////////////////////////////////////////////////////////////
