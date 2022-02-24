/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_decimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:44:12 by sbos          ########   odam.nl         */
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
	{
		conversion->base_str = ft_nbr_to_str(-nbr, 10);
		conversion->prefix = ft_strdup("-");
	}
	else
	{
		conversion->base_str = ft_nbr_to_str(nbr, 10);
		if (conversion->options.flags.plus_space)
			conversion->prefix = ft_strdup(" ");
		else if (conversion->options.flags.plus_space)
			conversion->prefix = ft_strdup("+");
		else
			conversion->prefix = ft_strdup("");
	}
}

////////////////////////////////////////////////////////////////////////////////
