/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   experiment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:04:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/18 15:18:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum e_alignment {
	LEFT,
	RIGHT,
}	t_alignment;

typedef struct s_flags
{
	t_alignment	alignment;
	bool		zero_fill;
	bool		plus_sign;
	bool		plus_space;
}	t_flags;

typedef struct s_options
{
	t_flags	flags;
	int		field_width;
	int		precision;
}	t_options;

void	initialize_options(t_options *format)
{
	format->flags.alignment = RIGHT;
	format->flags.zero_fill = false;
	format->flags.plus_sign = false;
	format->flags.plus_space = false;
	format->field_width = 0;
	format->precision = -1;
}

int	main(void)
{
	t_options	format;

	initialize_options(&format);
	printf("%d\n", format.flags.zero_fill);
	return (EXIT_SUCCESS);
}
