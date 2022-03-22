/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_fill_parts.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:16:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/22 11:54:13 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	set_left_right_pad(t_options *options, char *pad)
{
	if (options->flags.zero_pad)
	{
		free(pad);
		if (ft_empty_str_assign_fail(&options->parts.left_pad))
			return (ERROR);
		if (ft_empty_str_assign_fail(&options->parts.right_pad))
			return (ERROR);
	}
	else if (options->flags.pad_right)
	{
		if (ft_empty_str_assign_fail(&options->parts.left_pad))
			return (ERROR);
		options->parts.right_pad = pad;
	}
	else
	{
		options->parts.left_pad = pad;
		if (ft_empty_str_assign_fail(&options->parts.right_pad))
			return (ERROR);
	}
	return (SUCCESS);
}

STATIC t_success	set_space_pad(t_options *options)
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
			if (ft_str_assign_fail(&pad, ft_chr_repeat(' ', pad_len)))
				return (ERROR);
		}
	}
	if (pad == NULL && ft_empty_str_assign_fail(&pad))
		return (ERROR);
	return (set_left_right_pad(options, pad));
}

STATIC t_success	set_zero_pad(t_options *options)
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
			if (ft_str_assign_fail(&options->parts.precision_or_zero_pad,
					ft_chr_repeat('0', pad_len)))
				return (ERROR);
		}
	}
	return (SUCCESS);
}

STATIC t_success	set_precision_str(t_options *options)
{
	size_t	base_len;
	size_t	precision_len;

	if (ft_strchr(PRECISION_TYPES, options->type) != NULL)
	{
		base_len = ft_strlen(options->parts.base_str);
		if (options->precision > (ssize_t)base_len)
		{
			precision_len = (size_t)options->precision - base_len;
			if (ft_str_assign_fail(&options->parts.precision_or_zero_pad,
					ft_chr_repeat('0', precision_len)))
				return (ERROR);
		}
	}
	return (SUCCESS);
}

t_success	pft_fill_parts(t_options *options)
{
	if (options->precision >= 0)
	{
		if (ft_error(set_precision_str(options)))
			return (ERROR);
	}
	else if (options->flags.zero_pad)
	{
		if (ft_error(set_zero_pad(options)))
			return (ERROR);
	}
	if (options->parts.precision_or_zero_pad == NULL
		&& ft_empty_str_assign_fail(&options->parts.precision_or_zero_pad))
		return (ERROR);
	return (set_space_pad(options));
}

////////////////////////////////////////////////////////////////////////////////
