/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 16:43:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>		// printf()
# include <stdlib.h>	// EXIT_SUCCESS

////////////////////////////////////////////////////////////////////////////////

#define TEST(test_function) {void test_##test_function(void);printf("Calling function '" #test_function "'\n");test_##test_function();}

////////////////////////////////////////////////////////////////////////////////

void	test_fill_options_and_subfunctions(void)
{
	TEST(initialize_options);
	TEST(parse_flags);
	TEST(parse_field_width);
	TEST(parse_precision);
	TEST(fix_priorities);
	TEST(fill_options);
}

void	test_get_type_strings(void)
{
	TEST(get_char);
	TEST(get_decimal);
	TEST(get_hex_lower);
	TEST(get_hex_upper);
	TEST(get_percent);
	TEST(get_pointer);
	TEST(get_unsigned);
	TEST(get_string);
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
	// system("leaks tester");
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
