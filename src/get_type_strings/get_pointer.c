/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pointer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 17:07:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

void	get_pointer(va_list arg_ptr, t_conversion *conversion)
{
	const void	*address = va_arg(arg_ptr, void *);

	if (address == NULL && conversion->options.precision == 0)
		conversion->base_str = ft_strdup("");
	else
		conversion->base_str = ft_unsigned_nbr_to_str((uintmax_t)address, 16);
	conversion->prefix = ft_strdup("0x");
}

////////////////////////////////////////////////////////////////////////////////
