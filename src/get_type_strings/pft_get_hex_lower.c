/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_hex_lower.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 18:32:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

void	pft_get_hex_lower(va_list arg_ptr, t_options *options)
{
	const unsigned int	nbr = va_arg(arg_ptr, unsigned int);

	if (nbr == 0 && options->precision == 0)
		options->parts.base_str = ft_empty_str();
	else
		options->parts.base_str = ft_unsigned_nbr_to_str(nbr, 16);
	if (options->flags.alternate && nbr != 0)
		options->parts.prefix = ft_strdup("0x");
	else
		options->parts.prefix = ft_empty_str();
}

////////////////////////////////////////////////////////////////////////////////
