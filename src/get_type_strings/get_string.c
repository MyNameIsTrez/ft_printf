/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/25 18:43:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

void	get_string(va_list arg_ptr, t_options *options)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	if (options->precision >= 0)
		options->parts.base_str = ft_substr(str, 0,
				(size_t)options->precision);
	else
		options->parts.base_str = ft_strdup(str);
	options->parts.prefix = ft_strdup("");
}

////////////////////////////////////////////////////////////////////////////////
