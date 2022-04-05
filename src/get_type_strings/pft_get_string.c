/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 16:00:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_success	pft_get_string(va_list arg_ptr, t_options *options)
{
	char	*str;

	str = va_arg(arg_ptr, char *);
	if (str == NULL)
		str = "(null)";
	if (options->precision >= 0)
	{
		if (ft_str_assign(&options->parts.base_str, ft_substr(str, 0,
					(size_t)options->precision)) != SUCCESS)
			return (ERROR);
	}
	else
		if (ft_str_assign(&options->parts.base_str, ft_strdup(str)) != SUCCESS)
			return (ERROR);
	if (ft_empty_str_assign(&options->parts.prefix) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
