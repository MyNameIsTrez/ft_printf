/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 16:31:33 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

void	test_get_string(void)
{
	test_get_type_string(get_string, "", "");
	test_get_type_string(get_string, "1", "1");
	test_get_type_string(get_string, "42", "42");
	test_get_type_string(get_string, "hello", (char []){'h', 'e', 'l', 'l', 'o', '\0'});
}

////////////////////////////////////////////////////////////////////////////////