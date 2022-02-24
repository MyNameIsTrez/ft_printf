/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hex_lower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:41:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_hex_lower(va_list arg_ptr, t_conversion *conversion)
{
	conversion->base_str = ft_unsigned_nbr_to_str(
			va_arg(arg_ptr, unsigned int), 16);
	if (conversion->options.flags.alternate)
		conversion->prefix = ft_strdup("0x");
	else
		conversion->prefix = ft_strdup("");
}

////////////////////////////////////////////////////////////////////////////////
