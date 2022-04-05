/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:14:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/05 16:07:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

t_success	pft_accumulate(ssize_t ret, size_t *acc)
{
	if (ret < 0)
		return (ERROR);
	if (acc != NULL)
		(*acc) += (size_t)ret;
	return (SUCCESS);
}

t_success	pft_putstr(char *str, size_t *acc)
{
	return (pft_accumulate(ft_putstr(str), acc));
}

t_success	pft_putchar(char chr, size_t *acc)
{
	return (pft_accumulate(ft_putchar(chr), acc));
}

t_success	pft_put_substr(char *start, char *end, size_t *acc)
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
