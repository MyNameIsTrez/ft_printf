/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fix_priorities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:29:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(fix_priorities)
{
	{
		t_conversion	conversion;

		initialize_state(&conversion);

		conversion.options.flags.zero_fill = true;
		conversion.options.precision = 3;

		fix_priorities(&conversion);

		// printf("'%04d'\n", 42) -> '0042'
		// printf("'%04.3d'\n", 42) -> ' 042'
		massert(conversion.options.flags.zero_fill, (bool)false);
	}
}

////////////////////////////////////////////////////////////////////////////////
