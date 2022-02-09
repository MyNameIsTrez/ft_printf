/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 16:26:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

// t_list *g_tests_lst = NULL;
// #define Test(name) void test_##name(void); ft_lst_new_front(&g_tests_lst, &test_##name); void test_##name(void)
////////////////////////////////////////////////////////////////////////////////

// Test(get_pointer)
void	test_get_pointer(void)
{
	{
		test_get_type_string(get_pointer, "0x1", 1);
	}
	{
		unsigned int	a = 5;
		unsigned int	*b = &a;
		char	*str = NULL;

		asprintf(&str, "%p", b);
		// str[0] = 'E';
		test_get_type_string(get_pointer, str, b);
		free(str);
	}
}

////////////////////////////////////////////////////////////////////////////////
