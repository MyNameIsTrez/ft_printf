/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_priorities.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:19:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 17:20:06 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	fix_priorities(t_options *options)
{
	if (options->precision >= 0 && options->type == '%')
		options->precision = -1;
	if (options->flags.zero_fill && options->precision >= 0)
		options->flags.zero_fill = false;
	if (options->flags.zero_fill && options->flags.pad_right)
		options->flags.zero_fill = false;
}

////////////////////////////////////////////////////////////////////////////////
