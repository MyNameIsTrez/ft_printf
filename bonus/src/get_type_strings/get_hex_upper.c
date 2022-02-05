/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hex_upper.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/05 15:04:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

char	*get_hex_upper(va_list *arg_ptr)
{
	return (ft_str_upper(get_hex_lower(arg_ptr)));
}

////////////////////////////////////////////////////////////////////////////////
