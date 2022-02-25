/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_decimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:04:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_decimal(va_list arg_ptr, t_conversion *conversion)
{
	int const	nbr = va_arg(arg_ptr, int);

	if (nbr < 0)
	{
		conversion->options.parts.base_str = ft_nbr_to_str(-(intmax_t)nbr, 10);
		conversion->options.parts.prefix = ft_strdup("-");
	}
	else
	{
		if (nbr == 0 && conversion->options.precision == 0)
			conversion->options.parts.base_str = ft_strdup("");
		else
			conversion->options.parts.base_str = ft_nbr_to_str((intmax_t)nbr, 10);
		if (conversion->options.flags.plus_space)
			conversion->options.parts.prefix = ft_strdup(" ");
		else if (conversion->options.flags.plus_sign)
			conversion->options.parts.prefix = ft_strdup("+");
		else
			conversion->options.parts.prefix = ft_strdup("");
	}
}

////////////////////////////////////////////////////////////////////////////////
