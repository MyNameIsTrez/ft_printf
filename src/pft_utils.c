/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:14:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/03 14:40:59 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

ssize_t	pft_accumulate(ssize_t ret, size_t *acc)
{
	if (ret < 0)
		return (ret);
	if (acc != NULL)
		(*acc) += (size_t)ret;
	return (ret);
}

ssize_t	pft_putstr(char *str, size_t *acc)
{
	return (pft_accumulate(ft_putstr(str), acc));
}

ssize_t	pft_putchr(char chr, size_t *acc)
{
	return (pft_accumulate(ft_putchar(chr), acc));
}

ssize_t	pft_put_substr(char *start, char *end, size_t *acc)
{
	return (pft_accumulate(ft_put_substr(start, end), acc));
}

void	pft_free_parts(t_parts *parts)
{
	free(parts->left_pad);
	free(parts->prefix);
	free(parts->precision_or_zero_pad);
	free(parts->base_str);
	free(parts->right_pad);
}

////////////////////////////////////////////////////////////////////////////////
