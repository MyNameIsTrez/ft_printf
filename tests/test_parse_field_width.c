/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_parse_field_width.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:34:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/22 15:40:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(parse_field_width)
{
	{
		const char *format = "42d";
		t_state	state;

		initialize_state(&state);
		parse_field_width(&format, &state);

		massert(state.field_width, (size_t)42);
		massert(*format, (char)'d');
	}

	{
		const char *format = "d";
		t_state	state;

		initialize_state(&state);
		parse_field_width(&format, &state);

		massert(state.field_width, (size_t)0);
		massert(*format, (char)'d');
	}
}

////////////////////////////////////////////////////////////////////////////////
