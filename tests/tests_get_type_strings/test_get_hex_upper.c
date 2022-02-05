/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_hex_upper.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/04 18:32:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_hex_upper(void)
{
	test_get_type_string(get_hex_upper, "0", 0);

	test_get_type_string(get_hex_upper, "1", 1);
	test_get_type_string(get_hex_upper, "9", 9);
	test_get_type_string(get_hex_upper, "A", 10);
	test_get_type_string(get_hex_upper, "F", 15);
	test_get_type_string(get_hex_upper, "10", 16);
	test_get_type_string(get_hex_upper, "11", 17);

	test_get_type_string(get_hex_upper, "-1", -1);
	test_get_type_string(get_hex_upper, "-9", -9);
	test_get_type_string(get_hex_upper, "-A", -10);
	test_get_type_string(get_hex_upper, "-F", -15);
	test_get_type_string(get_hex_upper, "-10", -16);
	test_get_type_string(get_hex_upper, "-11", -17);
}

////////////////////////////////////////////////////////////////////////////////