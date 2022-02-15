/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:27 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/15 16:22:31 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // write, STDOUT_FILENO
#include <stdlib.h> // free

////////////////////////////////////////////////////////////////////////////////

void	print_with_padding(char *conversion_str, t_state *state,
								int total_width)
{
	(void)state;
	write(STDOUT_FILENO, conversion_str, (size_t)total_width + 1);
	// (void)conversion_str;
	// write(STDOUT_FILENO, buffer, total_width + 1);
}

void	apply_precision(t_state *state)
{
	if (state->conversion_type == 'c')
	{

	}
	else if (state->conversion_type == 'p')
	{

	}
	else if (state->conversion_type == 's')
	{

	}
	else if (ft_strchr(CONVERSION_NUMBER_TYPES, state->conversion_type))
	{
		// if (state->precision == 0)
		// {
		// 	free(state->conversion_str);
		// 	state->conversion_str = ft_strdup("");
		// }
	}
}

// TODO: Can this function get *conversion_table as an arg
//       so the return doesn't need to make a copy of it constantly?
const t_conversion_function	*get_conversion_table(void)
{
	// TODO: Which one should be used?
	// static const t_conversion_function	conversion_table[] = {
	// t_conversion_function static	conversion_table[] = {
	const static t_conversion_function	conversion_table[] = {
	['c'] = get_char,
	['s'] = get_string,
	['p'] = get_pointer,
	['d'] = get_decimal,
	['i'] = get_decimal,
	['u'] = get_unsigned,
	['x'] = get_hex_lower,
	['X'] = get_hex_upper,
	['%'] = get_percent,
	};

	return (conversion_table);
}

int	print(t_state *state)
{
	// int		total_width;

	// if (ft_strchr(CONVERSION_TYPES, state->conversion_type) != NULL)
	// {
	// 	apply_precision(state);
	// 	total_width = ft_max((int)ft_strlen(conversion_str),
	// 			state->field_width);
	// 	print_with_padding(conversion_str, state, total_width);
	// 	return (total_width);
	// }
	// else
	// {
	// 	return (42);
	// }
	(void)state;
	return (42);
}

// TODO: Would making conversion_table here a static
//       prevent calling get_conversion_table() a second time or help somehow?
void	parse_argument(t_state *state, va_list arg_ptr)
{
	const t_conversion_function	*conversion_table = get_conversion_table();

	conversion_table[state->conversion_type](arg_ptr, state);
}

void	fix_priorities(t_state *state)
{
	if (state->flags.zero_fill && state->precision >= 0)
	{
		state->flags.zero_fill = false;
	}
}

void	parse_conversion_type(const char **format, t_state *state)
{
	state->conversion_type = (unsigned char)**format;
}

void	parse_precision(const char **format, t_state *state)
{
	if (**format == '.')
	{
		state->precision = 0;
		(*format)++;
	}
	if (ft_isdigit(**format))
	{
		state->precision = ft_atoi(*format);
		(*format) += ft_get_digit_count(state->precision);
	}
}

void	parse_field_width(const char **format, t_state *state)
{
	state->field_width = ft_atoi(*format);
	if (state->field_width != 0)
		(*format) += ft_get_digit_count(state->field_width);
}

void	parse_flags(const char **format, t_state *state)
{
	while (**format != '\0' && ft_strchr(FLAGS, **format) != NULL)
	{
		if (**format == '#')
			state->flags.alternate = true;
		else if (**format == '0')
			state->flags.zero_fill = true;
		else if (**format == '-')
			state->flags.aligned_left = true;
		else if (**format == ' ')
			state->flags.plus_space = true;
		else if (**format == '+')
			state->flags.plus_sign = true;
		(*format)++;
	}
}

// precision is -1 by default instead of 0
// as it signifies using the length of the number/string/etc.
// printf("%d", 0) -> '0' but
// printf("%.d", 0) -> '', printf("%.0d", 0) -> '' and printf("%.1d", 0) -> '0'
void	initialize_state(t_state *state)
{
	state->flags.alternate = false;
	state->flags.zero_fill = false;
	state->flags.aligned_left = false;
	state->flags.plus_space = false;
	state->flags.plus_sign = false;
	state->field_width = 0;
	state->precision = -1;
	state->conversion_type = '\0';
	state->negative = false; // TODO: Necessary?
	state->conversion_str = NULL; // TODO: Necessary?
}

// TODO: Switch the arguments format and state around
void	parse_format(const char **format, t_state *state)
{
	initialize_state(state);
	parse_flags(format, state);
	parse_field_width(format, state);
	parse_precision(format, state);
	parse_conversion_type(format, state);
	fix_priorities(state);
}

int	ft_printf(const char *format, ...)
{
	t_state	state;
	int		chars_printed;
	va_list	arg_ptr;

	chars_printed = 0;
	va_start(arg_ptr, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			parse_format(&format, &state);
			if (state.conversion_type != '%')
			{
				parse_argument(&state, arg_ptr);
				// apply_precision(&state);
			}
			chars_printed += print(&state);
		}
		format++;
	}
	va_end(arg_ptr);
	return (chars_printed);
}
