/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_decimal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 20:18:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_decimal(va_list arg_ptr, t_options *options)
{
	int const	nbr = va_arg(arg_ptr, int);

	if (nbr < 0)
	{
		options->parts.base_str = ft_nbr_to_str(-(intmax_t)nbr, 10);
		options->parts.prefix = ft_strdup("-");
	}
	else
	{
		if (nbr == 0 && options->precision == 0)
			options->parts.base_str = ft_empty_str();
		else
			options->parts.base_str = ft_nbr_to_str((intmax_t)nbr, 10);
		if (options->flags.plus_space)
			options->parts.prefix = ft_strdup(" ");
		else if (options->flags.plus_sign)
			options->parts.prefix = ft_strdup("+");
		else
			options->parts.prefix = ft_empty_str();
	}
}

////////////////////////////////////////////////////////////////////////////////
