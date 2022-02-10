/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_hex_upper.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/10 12:42:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(get_hex_upper)
{
	test_get_type_string(get_hex_upper, "0", 0);

	test_get_type_string(get_hex_upper, "1", 1);
	test_get_type_string(get_hex_upper, "9", 9);
	test_get_type_string(get_hex_upper, "A", 10);
	test_get_type_string(get_hex_upper, "F", 15);
	test_get_type_string(get_hex_upper, "10", 16);
	test_get_type_string(get_hex_upper, "11", 17);

	test_get_type_string(get_hex_upper, "FFFFFFFF", -1);
	test_get_type_string(get_hex_upper, "FFFFFFF7", -9);
	test_get_type_string(get_hex_upper, "FFFFFFF6", -10);
	test_get_type_string(get_hex_upper, "FFFFFFF1", -15);
	test_get_type_string(get_hex_upper, "FFFFFFF0", -16);
	test_get_type_string(get_hex_upper, "FFFFFFEF", -17);
}

////////////////////////////////////////////////////////////////////////////////
