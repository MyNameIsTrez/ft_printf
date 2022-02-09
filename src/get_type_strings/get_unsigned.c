/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_unsigned.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 15:39:45 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

char	*get_unsigned(va_list arg_ptr)
{
	return (ft_unsigned_nbr_to_str(va_arg(arg_ptr, unsigned int), 10));
}

////////////////////////////////////////////////////////////////////////////////