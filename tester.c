/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 12:16:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests/tests.h"

////////////////////////////////////////////////////////////////////////////////

#include "bonus/src/ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#define TEST(test_function) {printf("Calling function '" #test_function "'\n");test_function();}

////////////////////////////////////////////////////////////////////////////////

void	run_tests(void)
{
	TEST(test_initialize_options);
	TEST(test_parse_flags);
	// TEST(test_parse_field_width);
	// TEST(test_parse_precision);
	// TEST(test_fix_priorities);
	TEST(test_fill_options);
}

int	main(void)
{
	printf("Running tests...\n");
	run_tests();
	printf("Tests ran successfully!\n");
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
