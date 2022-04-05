/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_initialize_options.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:05:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/04 16:39:50 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	initialize_parts(t_parts *parts)
{
	parts->left_pad = NULL;
	parts->prefix = NULL;
	parts->precision_or_zero_pad = NULL;
	parts->base_str = NULL;
	parts->right_pad = NULL;
}

STATIC void	initialize_flags(t_flags *flags)
{
	flags->alternate = false;
	flags->zero_pad = false;
	flags->pad_right = false;
	flags->plus_space = false;
	flags->plus_sign = false;
}

// precision is -1 by default instead of 0 cause:
// printf("'%d'\n", 0) -> '0' but printf("'%.d'\n", 0) -> ''
void	pft_initialize_options(t_options *options)
{
	initialize_flags(&options->flags);
	initialize_parts(&options->parts);
	options->field_width = 0;
	options->precision = -1;
	options->type = '\0';
}

////////////////////////////////////////////////////////////////////////////////
