/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_fix_priorities.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:19:54 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/23 15:44:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

void	pft_fix_priorities(t_options *options)
{
	if (options->precision >= 0 && options->type == '%')
		options->precision = -1;
	if (options->flags.zero_pad && options->precision >= 0)
		options->flags.zero_pad = false;
	if (options->flags.zero_pad && options->flags.pad_right)
		options->flags.zero_pad = false;
	if (options->flags.plus_sign && options->flags.plus_space)
		options->flags.plus_space = false;
}

////////////////////////////////////////////////////////////////////////////////
