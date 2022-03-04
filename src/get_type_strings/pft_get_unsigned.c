/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 18:16:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////
