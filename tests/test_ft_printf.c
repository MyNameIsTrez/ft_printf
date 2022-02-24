/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_printf.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 17:56:28 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 18:00:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////

Test(ft_printf)
{
	{
		compare_printfs("%c", 'a');
		compare_printfs("%.c", 'a');
		compare_printfs("%-c", 'a');
		compare_printfs("%-.c", 'a');
		compare_printfs("%1c", 'a');
		compare_printfs("%3c", 'a');
		compare_printfs("%-3c", 'a');
	}
	{
		compare_printfs("%s", "");
		compare_printfs("%s", "foo");
		compare_printfs("%-s", "foo");
		compare_printfs("%.s", "foo");
		compare_printfs("%-.s", "foo");
		compare_printfs("%1s", "foo");
		compare_printfs("%5s", "foo");
		compare_printfs("%-5s", "foo");
		compare_printfs("%.2s", "foo");
		compare_printfs("%-.5s", "foo");
	}
	{
		compare_printfs("%p", (void *)0x42);
		compare_printfs("%p", (void *)0x0);
		compare_printfs("%.p", (void *)0x0);
		compare_printfs("%.p", (void *)0x7);
		compare_printfs("%1p", (void *)0x42);
		compare_printfs("%5p", (void *)0x42);
		compare_printfs("%-5p", (void *)0x42);
	}
	{
		compare_printfs("%d", 5);
		compare_printfs("%d", 0);
		compare_printfs("%d", -5);
		compare_printfs("%d", 51);
		compare_printfs("%.1d", 51);
		compare_printfs("%.4d", 51);
		compare_printfs("%d", INT32_MAX);
		compare_printfs("%d", INT32_MIN);
		compare_printfs("%1d", 42);
		compare_printfs("%5d", 42);
		compare_printfs("%-5d", 42);
		compare_printfs("%1d", -42);
		compare_printfs("%5d", -42);
		compare_printfs("%-5d", -42);
		compare_printfs("% d", 5);
		compare_printfs("%+d", 5);
		compare_printfs("% .d", 0);
		compare_printfs("%+.d", 0);
	}
	{
		compare_printfs("%u", 5);
		compare_printfs("%u", 0);
		compare_printfs("%u", -5);
		compare_printfs("%u", 51);
		compare_printfs("%.1u", 51);
		compare_printfs("%.4u", 51);
		compare_printfs("%u", UINT32_MAX);
		compare_printfs("%1u", 42);
		compare_printfs("%5u", 42);
		compare_printfs("%-5u", 42);
	}
	{
		compare_printfs("%x", 5);
		compare_printfs("%#x", 0);
		compare_printfs("%#.x", 0);
		compare_printfs("%.1x", 51);
		compare_printfs("%.4x", 51);
		compare_printfs("%1x", 0x42);
		compare_printfs("%5x", 0x42);
		compare_printfs("%-5x", 0x42);
	}
	{
		compare_printfs("%X", 5);
		compare_printfs("%#X", 0);
		compare_printfs("%#.X", 0);
		compare_printfs("%.1X", 51);
		compare_printfs("%.4X", 51);
		compare_printfs("%1X", 0x42);
		compare_printfs("%5X", 0x42);
		compare_printfs("%-5X", 0x42);
	}
	{
		compare_printfs("%%");
		compare_printfs("%.%");
		compare_printfs("%.1%");
		compare_printfs("%.5%");
		compare_printfs("%0%");
		compare_printfs("%01%");
		compare_printfs("%05%");
		compare_printfs("%1%");
		compare_printfs("%5%");
		compare_printfs("%-5%");
	}
}

////////////////////////////////////////////////////////////////////////////////
