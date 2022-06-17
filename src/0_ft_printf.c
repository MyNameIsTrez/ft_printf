/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   0_ft_printf.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/05/25 17:13:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf.h"

////////////////////////////////////////////////////////////////////////////////

STATIC t_success	pft_print_options(t_options *options)
{
	if (pft_putstr(options->parts.left_pad, &options->len) != SUCCESS)
		return (ERROR);
	if (pft_putstr(options->parts.prefix, &options->len) != SUCCESS)
		return (ERROR);
	if (pft_putstr(options->parts.precision_or_zero_pad,
			&options->len) != SUCCESS)
		return (ERROR);
	if (options->type == 'c')
	{
		if (pft_putchar(options->parts.base_str[0], &options->len) != SUCCESS)
			return (ERROR);
	}
	else if (pft_putstr(options->parts.base_str, &options->len) != SUCCESS)
		return (ERROR);
	if (pft_putstr(options->parts.right_pad, &options->len) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}

STATIC t_success	pft_printf_loop(char *format, char **non_format_start,
									t_options *options, va_list arg_ptr)
{
	while (*format != '\0')
	{
		pft_initialize_options(options);
		format = ft_strchr(format, '%');
		if (format == NULL)
			break ;
		if (pft_put_substr(*non_format_start, format, &options->len) != SUCCESS)
			return (ERROR);
		format++;
		pft_parse_format(&format, options);
		if (pft_parse_argument(options, arg_ptr) != SUCCESS)
			return (pft_free_parts(&options->parts));
		if (pft_fill_parts(options) != SUCCESS)
			return (pft_free_parts(&options->parts));
		if (pft_print_options(options) != SUCCESS)
			return (pft_free_parts(&options->parts));
		pft_free_parts(&options->parts);
		format++;
		*non_format_start = format;
	}
	return (SUCCESS);
}

/**
 * @brief This is a recreation of printf() from libc.
 * It doesn’t implement the buffer management of the original printf().
 * It handles the following conversions: "cspdiuxX%" .
 * It handles any combination of the following flags: "-0.# +"
 * and the minimum field width.
 *
 * @param format See "man 3 printf".
 *
 * @return If successful, returns the number of characters printed
 * (excluding the null terminator).
 * If an output error is encountered, a negative value is returned.
 */
int	ft_printf(const char *format, ...)
{
	t_options	options;
	va_list		arg_ptr;
	char		*non_format_start;

	options.len = 0;
	non_format_start = (char *)format;
	va_start(arg_ptr, format);
	if (pft_printf_loop((char *)format, &non_format_start, &options, arg_ptr)
		!= SUCCESS)
		return (-1);
	if (pft_putstr(non_format_start, &options.len) != SUCCESS)
		return (-1);
	va_end(arg_ptr);
	return ((int)options.len);
}
