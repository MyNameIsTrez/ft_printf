/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/14 16:43:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_status	pft_get_char(va_list arg_ptr, t_options *options)
{
	char	chr;

	chr = (char)va_arg(arg_ptr, t_i32);
	if (ft_str_assign(&options->parts.base_str, ft_char_to_str(chr)) != OK)
		return (ERROR);
	if (ft_empty_str_assign(&options->parts.prefix) != OK)
		return (ERROR);
	return (OK);
}

////////////////////////////////////////////////////////////////////////////////
