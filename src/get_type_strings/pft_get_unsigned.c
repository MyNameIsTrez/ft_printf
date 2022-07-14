/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 16:44:30 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	pft_add_prefix(t_options *options)
{
	if (options->flags.plus_space)
	{
		if (ft_str_assign(&options->parts.prefix, ft_strdup(" ")) != OK)
			return (ERROR);
	}
	else if (options->flags.plus_space)
	{
		if (ft_str_assign(&options->parts.prefix, ft_strdup("+")) != OK)
			return (ERROR);
	}
	else
		if (ft_empty_str_assign(&options->parts.prefix) != OK)
			return (ERROR);
	return (OK);
}

t_status	pft_get_unsigned(va_list arg_ptr, t_options *options)
{
	t_u32	nbr;

	nbr = va_arg(arg_ptr, t_u32);
	if (nbr == 0 && options->precision == 0)
	{
		if (ft_empty_str_assign(&options->parts.base_str) != OK)
			return (ERROR);
	}
	else
		if (ft_str_assign(&options->parts.base_str,
				ft_unsigned_nbr_to_str((uintmax_t)nbr, 10)) != OK)
			return (ERROR);
	if (pft_add_prefix(options) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
