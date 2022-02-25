/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_options_table.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 13:01:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/22 15:40:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(get_options_table)
{
	const t_base_and_prefix_fn	*options_table = get_options_table();

	massert((void *)options_table['c'], (void *)get_char);
	massert((void *)options_table['s'], (void *)get_string);
	massert((void *)options_table['p'], (void *)get_pointer);
	massert((void *)options_table['d'], (void *)get_decimal);
	massert((void *)options_table['i'], (void *)get_decimal);
	massert((void *)options_table['u'], (void *)get_unsigned);
	massert((void *)options_table['x'], (void *)get_hex_lower);
	massert((void *)options_table['X'], (void *)get_hex_upper);
	massert((void *)options_table['%'], (void *)get_percent);
}

////////////////////////////////////////////////////////////////////////////////
