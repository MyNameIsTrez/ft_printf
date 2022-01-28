/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fix_priorities.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/28 15:27:18 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_fix_priorities(void)
{
	{
		t_options	options;

		initialize_options(&options);

		options.flags.zero_fill = true;
		options.precision = 3;

		fix_priorities(&options);

		// printf("'%04d'\n", 42) -> '0042'
		// printf("'%04.3d'\n", 42) -> ' 042'
		ASSERT_INT(options.flags.zero_fill, false);
	}
}

////////////////////////////////////////////////////////////////////////////////
