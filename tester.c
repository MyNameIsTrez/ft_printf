/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/17 17:03:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "bonus/src/ft_printf_bonus.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

void test(const char *format)
{
	// TODO: Check if the outputs to stdout are equal by piping to temporary files.
	// const int	number_of_characters_ft_printed = ft_printf("a: %s, b: %d, c: %c", "foo", 42, 'x');
	ft_printf("a: %s, b: %d, c: %c", "foo", 42, 'x');
	// const int	number_of_characters_libc_printed = printf("foo");
	(void)format;
	// printf("Format: %s, ft: %d, libc: %d\n", format, number_of_characters_ft_printed, number_of_characters_libc_printed);
	// assert(number_of_characters_ft_printed == number_of_characters_libc_printed);
}

int	main(void)
{
	const char	*format = "Hello World Bonus!";
	test(format);
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
