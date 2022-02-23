/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_decimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:29:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_decimal(va_list arg_ptr, t_conversion *conversion)
{
	intmax_t const	nbr = va_arg(arg_ptr, int);

	conversion->options.negative = nbr < 0;
	if (nbr < 0)
		conversion->conversion_str = ft_nbr_to_str(-nbr, 10);
	else
		conversion->conversion_str = ft_nbr_to_str(nbr, 10);
}

////////////////////////////////////////////////////////////////////////////////
