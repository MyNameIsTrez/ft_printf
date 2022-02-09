/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 13:55:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "bonus/src/ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include "tests/tests.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>		// printf()
# include <stdlib.h>	// EXIT_SUCCESS

////////////////////////////////////////////////////////////////////////////////

#define TEST(test_function) {printf("Calling function '" #test_function "'\n");test_function();}

////////////////////////////////////////////////////////////////////////////////

void	test_fill_options_and_subfunctions(void)
{
	TEST(test_initialize_options);
	TEST(test_parse_flags);
	TEST(test_parse_field_width);
	TEST(test_parse_precision);
	TEST(test_fix_priorities);
	TEST(test_fill_options);
}

void	test_get_type_strings(void)
{
	TEST(test_get_char);
	TEST(test_get_decimal);
	TEST(test_get_hex_lower);
	TEST(test_get_hex_upper);
	TEST(test_get_percent);
	TEST(test_get_pointer);
}

////////////////////////////////////////////////////////////////////////////////

void	run_tests(void)
{
	test_fill_options_and_subfunctions();
	test_get_type_strings();
}

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	printf("Running tests...\n");
	run_tests();
	printf("Tests ran successfully!\n");
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
