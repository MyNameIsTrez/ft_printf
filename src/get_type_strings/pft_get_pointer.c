/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_pointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 18:44:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>	// TODO: Includes what?

////////////////////////////////////////////////////////////////////////////////

t_success	pft_get_pointer(va_list arg_ptr, t_options *options)
{
	void const	*address = va_arg(arg_ptr, void *);

	if (address == NULL && options->precision == 0)
	{
		if (ft_empty_str_assign_fail(&options->parts.base_str))
			return (ERROR);
	}
	else
		if (ft_str_assign_fail(&options->parts.base_str,
				ft_unsigned_nbr_to_str((uintmax_t)address, 16)))
			return (ERROR);
	if (ft_str_assign_fail(&options->parts.prefix, ft_strdup("0x")))
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
