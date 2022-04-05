/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_percent.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 16:43:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 15:58:20 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_success	pft_get_percent(va_list arg_ptr, t_options *options)
{
	(void)arg_ptr;
	if (ft_str_assign(&options->parts.base_str, ft_strdup("%")) != SUCCESS)
		return (ERROR);
	if (ft_empty_str_assign(&options->parts.prefix) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
