/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_is_empty.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/04 14:28:56 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 14:29:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_str.h"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Returns whether @p str is empty.
 *
 * @param str
 * @return
 */
bool	ft_str_is_empty(const char *str)
{
	return (ft_str_eq(str, ""));
}

////////////////////////////////////////////////////////////////////////////////
