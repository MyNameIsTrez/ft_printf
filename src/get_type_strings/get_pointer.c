/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pointer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:43:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

void	get_pointer(va_list arg_ptr, t_options *options)
{
	const void	*address = va_arg(arg_ptr, void *);

	if (address == NULL && options->precision == 0)
		options->parts.base_str = ft_strdup("");
	else
		options->parts.base_str = ft_unsigned_nbr_to_str((uintmax_t)address, 16);
	options->parts.prefix = ft_strdup("0x");
}

////////////////////////////////////////////////////////////////////////////////
