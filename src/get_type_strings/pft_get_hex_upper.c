/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_hex_upper.c                                :+:    :+:            */
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

t_success	pft_get_hex_upper(va_list arg_ptr, t_options *options)
{
	if (ft_error(pft_get_hex_lower(arg_ptr, options)))
		return (ERROR);
	ft_str_upper(options->parts.base_str);
	ft_str_upper(options->parts.prefix);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
