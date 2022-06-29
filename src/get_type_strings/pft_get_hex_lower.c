/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_hex_lower.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 12:49:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_status	pft_get_hex_lower(va_list arg_ptr, t_options *options)
{
	unsigned int const	nbr = va_arg(arg_ptr, unsigned int);

	if (nbr == 0 && options->precision == 0)
	{
		if (ft_empty_str_assign(&options->parts.base_str) != OK)
			return (ERROR);
	}
	else
		if (ft_str_assign(&options->parts.base_str,
				ft_unsigned_nbr_to_str(nbr, 16)) != OK)
			return (ERROR);
	if (options->flags.alternate && nbr != 0)
	{
		if (ft_str_assign(&options->parts.prefix,
				ft_strdup("0x")) != OK)
			return (ERROR);
	}
	else
		if (ft_empty_str_assign(&options->parts.prefix) != OK)
			return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
