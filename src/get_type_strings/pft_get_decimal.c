/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_decimal.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 16:03:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	pft_negative_decimal(int const nbr, t_options *options)
{
	if (nbr == 0 && options->precision == 0)
	{
		if (ft_empty_str_assign(&options->parts.base_str) != SUCCESS)
			return (ERROR);
	}
	else
		if (ft_str_assign(&options->parts.base_str,
				ft_nbr_to_str((intmax_t)nbr, 10)) != SUCCESS)
			return (ERROR);
	if (options->flags.plus_space)
	{
		if (ft_str_assign(&options->parts.prefix,
				ft_strdup(" ")) != SUCCESS)
			return (ERROR);
	}
	else if (options->flags.plus_sign)
	{
		if (ft_str_assign(&options->parts.prefix,
				ft_strdup("+")) != SUCCESS)
			return (ERROR);
	}
	else if (ft_empty_str_assign(&options->parts.prefix) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

t_success	pft_get_decimal(va_list arg_ptr, t_options *options)
{
	int const	nbr = va_arg(arg_ptr, int);

	if (nbr < 0)
	{
		if (ft_str_assign(&options->parts.base_str,
				ft_nbr_to_str(-(intmax_t)nbr, 10)) != SUCCESS)
			return (ERROR);
		if (ft_str_assign(&options->parts.prefix, ft_strdup("-")) != SUCCESS)
			return (ERROR);
	}
	else if (pft_negative_decimal(nbr, options) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
