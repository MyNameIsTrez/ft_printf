/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_decimal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 16:43:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	pft_negative_decimal(t_i32 const nbr, t_options *options)
{
	if (nbr == 0 && options->precision == 0)
	{
		if (ft_empty_str_assign(&options->parts.base_str) != OK)
			return (ERROR);
	}
	else
		if (ft_str_assign(&options->parts.base_str,
				ft_nbr_to_str((intmax_t)nbr, 10)) != OK)
			return (ERROR);
	if (options->flags.plus_space)
	{
		if (ft_str_assign(&options->parts.prefix,
				ft_strdup(" ")) != OK)
			return (ERROR);
	}
	else if (options->flags.plus_sign)
	{
		if (ft_str_assign(&options->parts.prefix,
				ft_strdup("+")) != OK)
			return (ERROR);
	}
	else if (ft_empty_str_assign(&options->parts.prefix) != OK)
		return (ERROR);
	return (OK);
}

t_status	pft_get_decimal(va_list arg_ptr, t_options *options)
{
	t_i32	nbr;

	nbr = va_arg(arg_ptr, t_i32);
	if (nbr < 0)
	{
		if (ft_str_assign(&options->parts.base_str,
				ft_nbr_to_str(-(intmax_t)nbr, 10)) != OK)
			return (ERROR);
		if (ft_str_assign(&options->parts.prefix, ft_strdup("-")) != OK)
			return (ERROR);
	}
	else if (pft_negative_decimal(nbr, options) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
