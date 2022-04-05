/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 15:04:38 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	add_prefix(t_options *options)
{
	if (options->flags.plus_space)
	{
		if (ft_str_assign_fail(&options->parts.prefix,
				ft_strdup(" ")))
			return (ERROR);
	}
	else if (options->flags.plus_space)
	{
		if (ft_str_assign_fail(&options->parts.prefix,
				ft_strdup("+")))
			return (ERROR);
	}
	else
		if (ft_empty_str_assign_fail(&options->parts.prefix))
			return (ERROR);
	return (SUCCESS);
}

t_success	pft_get_unsigned(va_list arg_ptr, t_options *options)
{
	unsigned int const	nbr = va_arg(arg_ptr, unsigned int);

	if (nbr == 0 && options->precision == 0)
	{
		if (ft_empty_str_assign_fail(&options->parts.base_str))
			return (ERROR);
	}
	else
		if (ft_str_assign_fail(&options->parts.base_str,
				ft_unsigned_nbr_to_str((uintmax_t)nbr, 10)))
			return (ERROR);
	if (add_prefix(options) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
