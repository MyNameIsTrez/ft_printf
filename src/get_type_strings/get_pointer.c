/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_pointer.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/24 13:42:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

void	get_pointer(va_list arg_ptr, t_conversion *conversion)
{
	const uintmax_t	address = (uintmax_t)va_arg(arg_ptr, void *);
	const char		*hex_address_str = ft_unsigned_nbr_to_str(address, 16);

	conversion->base_str = (char *)hex_address_str;
	conversion->prefix = ft_strdup("0x");
}

////////////////////////////////////////////////////////////////////////////////
