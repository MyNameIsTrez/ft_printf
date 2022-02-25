/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hex_upper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:04:57 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_hex_upper(va_list arg_ptr, t_conversion *conversion)
{
	get_hex_lower(arg_ptr, conversion);
	ft_str_upper(conversion->options.parts.base_str);
	ft_str_upper(conversion->options.parts.prefix);
}

////////////////////////////////////////////////////////////////////////////////
