/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 15:50:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

char	*get_string(va_list arg_ptr)
{
	return (ft_strdup(va_arg(arg_ptr, char *)));
}

////////////////////////////////////////////////////////////////////////////////
