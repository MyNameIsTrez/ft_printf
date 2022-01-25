/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_fill_options.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/24 17:28:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_fill_options(void)
{
	const char *format = "%+5d";
	t_options	options;

	fill_options(&format, &options);

	printf("options.flags.plus_sign is %d\n", options.flags.plus_sign);
	bool	tested_value = options.flags.plus_sign;
	bool	expected_value = true;
	assert(tested_value == expected_value);
}

////////////////////////////////////////////////////////////////////////////////
