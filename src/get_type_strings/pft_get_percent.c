/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_percent.c                                  :+:    :+:            */
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

t_success	pft_get_percent(va_list arg_ptr, t_options *options)
{
	(void)arg_ptr;
	if (ft_str_assign_fail(&options->parts.base_str, ft_strdup("%")))
		return (ERROR);
	if (ft_empty_str_assign_fail(&options->parts.prefix))
		return (ERROR);
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
