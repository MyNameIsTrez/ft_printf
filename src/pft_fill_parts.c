/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_fill_parts.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 17:16:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/01 18:32:10 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC void	set_left_right_pad(t_options *options, char *pad)
{
	if (options->flags.zero_pad)
	{
		free(pad);
		options->parts.left_pad = ft_empty_str();
		options->parts.right_pad = ft_empty_str();
	}
	else if (options->flags.pad_right)
	{
		options->parts.left_pad = ft_empty_str();
		options->parts.right_pad = pad;
	}
	else
	{
		options->parts.left_pad = pad;
		options->parts.right_pad = ft_empty_str();
	}
}

STATIC void	set_space_pad(t_options *options)
{
	const char	*pad = NULL;
	size_t		len;
	size_t		pad_len;

	if (!options->flags.zero_pad)
	{
		len = ft_strlen(options->parts.prefix)
			+ ft_strlen(options->parts.precision_or_zero_pad)
			+ ft_strlen(options->parts.base_str);
		if (options->type == 'c' && ft_str_eq(options->parts.base_str, ""))
			len++;
		if (options->field_width > len)
		{
			pad_len = options->field_width - len;
			pad = ft_chr_repeat(' ', pad_len);
		}
	}
	if (pad == NULL)
		pad = ft_empty_str();
	set_left_right_pad(options, (char *)pad);
}

STATIC void	set_zero_pad(t_options *options)
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
			options->parts.precision_or_zero_pad = ft_chr_repeat('0', pad_len);
		}
	}
}

STATIC void	set_precision_str(t_options *options)
{
	size_t	base_len;
	size_t	precision_len;

	if (ft_strchr(PRECISION_TYPES, options->type) != NULL)
	{
		base_len = ft_strlen(options->parts.base_str);
		if (options->precision > (ssize_t)base_len)
		{
			precision_len = (size_t)options->precision - base_len;
			options->parts.precision_or_zero_pad = ft_chr_repeat('0',
					precision_len);
		}
	}
}

void	pft_fill_parts(t_options *options)
{
	if (options->precision >= 0)
		set_precision_str(options);
	else if (options->flags.zero_pad)
		set_zero_pad(options);
	if (options->parts.precision_or_zero_pad == NULL)
		options->parts.precision_or_zero_pad = ft_empty_str();
	set_space_pad(options);
}

////////////////////////////////////////////////////////////////////////////////
