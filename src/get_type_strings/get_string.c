/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_string.c                                       :+:    :+:            */
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

void	get_string(va_list arg_ptr, t_conversion *conversion)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	if (conversion->options.precision >= 0)
		conversion->options.parts.base_str = ft_substr(str, 0,
				(size_t)conversion->options.precision);
	else
		conversion->options.parts.base_str = ft_strdup(str);
	conversion->options.parts.prefix = ft_strdup("");
}

////////////////////////////////////////////////////////////////////////////////
