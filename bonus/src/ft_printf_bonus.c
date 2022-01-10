/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: trez <trez@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 13:29:20 by trez          #+#    #+#                 */
/*   Updated: 2022/01/10 16:37:59 by trez          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * @brief This is a recreation of printf() from libc.
 * It doesn’t implement the buffer management of the original printf().
 * It handles the following conversions: "cspdiuxX%" .
 * It handles any combination of the following flags: "-0."
 * and the field minimum width under all conversions.
 * It handles all the following flags: "# +" (yes, one of them is a space).
 *
 * @param format See "man 3 printf".
 * 
 * @return If successful, returns the number of characters printed
 * (excluding the null terminator).
 * If an output error is encountered, a negative value is returned.
 */
int	ft_printf(const char *format, ...)
{
	printf("Hello World Bonus!\n");
	(void)format;
	return (0);
}
