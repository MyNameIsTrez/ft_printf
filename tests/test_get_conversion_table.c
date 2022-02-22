/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_conversion_table.c                        :+:    :+:            */
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

Test(get_conversion_table)
{
	const t_conversion_function	*conversion_table = get_conversion_table();

	massert((void *)conversion_table['c'], (void *)get_char);
	massert((void *)conversion_table['s'], (void *)get_string);
	massert((void *)conversion_table['p'], (void *)get_pointer);
	massert((void *)conversion_table['d'], (void *)get_decimal);
	massert((void *)conversion_table['i'], (void *)get_decimal);
	massert((void *)conversion_table['u'], (void *)get_unsigned);
	massert((void *)conversion_table['x'], (void *)get_hex_lower);
	massert((void *)conversion_table['X'], (void *)get_hex_upper);
	massert((void *)conversion_table['%'], (void *)get_percent);
}

////////////////////////////////////////////////////////////////////////////////
