/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: trez <trez@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 13:31:10 by trez          #+#    #+#                 */
/*   Updated: 2022/01/10 17:09:27 by trez          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/src/ft_printf_bonus.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void test(const char *format)
{
	// TODO: Check if the outputs to stdout are equal by piping to temporary files.
	const int	number_of_characters_ft_printed = ft_printf("foo");
	const int	number_of_characters_libc_printed = printf("foo");
	printf("Format: %s, ft: %d, libc: %d", format, number_of_characters_ft_printed, number_of_characters_libc_printed);
	assert(number_of_characters_ft_printed == number_of_characters_libc_printed);
}

int	main(void)
{
	const char	*format = "Hello World Bonus!\n";
	test(format);
	return (EXIT_SUCCESS);
}
