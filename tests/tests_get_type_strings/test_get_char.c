/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:47:24 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(get_char)
{
	test_get_type_string(get_char, "", "a", 'a');
}

////////////////////////////////////////////////////////////////////////////////
