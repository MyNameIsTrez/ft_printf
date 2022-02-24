/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_unsigned.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 17:10:04 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_unsigned(va_list arg_ptr, t_conversion *conversion)
{
	unsigned int const	nbr = va_arg(arg_ptr, unsigned int);

	if (nbr == 0 && conversion->options.precision == 0)
		conversion->base_str = ft_strdup("");
	else
		conversion->base_str = ft_unsigned_nbr_to_str((uintmax_t)nbr, 10);
	if (conversion->options.flags.plus_space)
		conversion->prefix = ft_strdup(" ");
	else if (conversion->options.flags.plus_space)
		conversion->prefix = ft_strdup("+");
	else
		conversion->prefix = ft_strdup("");
}

////////////////////////////////////////////////////////////////////////////////
