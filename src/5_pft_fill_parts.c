/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   5_pft_fill_parts.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:16:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 21:36:39 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_status	pft_set_left_right_pad(t_options *options, char *pad)
{
	if (options->flags.zero_pad)
	{
		ft_free(&pad);
		if (ft_empty_str_assign(&options->parts.left_pad) != OK)
			return (ERROR);
		if (ft_empty_str_assign(&options->parts.right_pad) != OK)
			return (ERROR);
	}
	else if (options->flags.pad_right)
	{
		options->parts.right_pad = pad;
		if (ft_empty_str_assign(&options->parts.left_pad) != OK)
			return (ERROR);
	}
	else
	{
		options->parts.left_pad = pad;
		if (ft_empty_str_assign(&options->parts.right_pad) != OK)
			return (ERROR);
	}
	return (OK);
}

STATIC t_status	pft_set_space_pad(t_options *options)
{
	char	*pad;
	size_t	len;
	size_t	pad_len;

	pad = NULL;
	if (!options->flags.zero_pad)
	{
		len = ft_strlen(options->parts.prefix)
			+ ft_strlen(options->parts.precision_or_zero_pad)
			+ ft_strlen(options->parts.base_str);
		if (options->type == 'c' && ft_str_is_empty(options->parts.base_str))
			len++;
		if (options->field_width > len)
		{
			pad_len = options->field_width - len;
			if (ft_str_assign(&pad, ft_chr_repeat(' ', pad_len)) != OK)
				return (ERROR);
		}
	}
	if (pad == NULL && ft_empty_str_assign(&pad) != OK)
		return (ERROR);
	return (pft_set_left_right_pad(options, pad));
}

STATIC t_status	pft_set_zero_pad(t_options *options)
{
	size_t	len;
	size_t	pad_len;

	if (ft_strchr(ZERO_PAD_TYPES, options->type) != NULL)
	{
		len = ft_strlen(options->parts.prefix)
			+ ft_strlen(options->parts.base_str);
		if (options->field_width > len)
		{
			pad_len = options->field_width - len;
			if (ft_str_assign(&options->parts.precision_or_zero_pad,
					ft_chr_repeat('0', pad_len)) != OK)
				return (ERROR);
		}
	}
	return (OK);
}

STATIC t_status	pft_set_precision_str(t_options *options)
{
	size_t	base_len;
	size_t	precision_len;

	if (ft_strchr(PRECISION_TYPES, options->type) != NULL)
	{
		base_len = ft_strlen(options->parts.base_str);
		if (options->precision > (ssize_t)base_len)
		{
			precision_len = (size_t)options->precision - base_len;
			if (ft_str_assign(&options->parts.precision_or_zero_pad,
					ft_chr_repeat('0', precision_len)) != OK)
				return (ERROR);
		}
	}
	return (OK);
}

t_status	pft_fill_parts(t_options *options)
{
	if (options->precision >= 0)
	{
		if (pft_set_precision_str(options) != OK)
			return (ERROR);
	}
	else if (options->flags.zero_pad)
	{
		if (pft_set_zero_pad(options) != OK)
			return (ERROR);
	}
	if (options->parts.precision_or_zero_pad == NULL
		&& ft_empty_str_assign(&options->parts.precision_or_zero_pad)
		!= OK)
		return (ERROR);
	return (pft_set_space_pad(options));
}

////////////////////////////////////////////////////////////////////////////////
