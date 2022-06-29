/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pft_get_type_strings.h                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 17:35:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/29 12:49:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef PFT_GET_TYPE_STRINGS_H
# define PFT_GET_TYPE_STRINGS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_options	t_options;

////////////////////////////////////////////////////////////////////////////////

t_status	pft_get_char(va_list arg_ptr, t_options *options);
t_status	pft_get_decimal(va_list arg_ptr, t_options *options);
t_status	pft_get_hex_lower(va_list arg_ptr, t_options *options);
t_status	pft_get_hex_upper(va_list arg_ptr, t_options *options);
t_status	pft_get_percent(va_list arg_ptr, t_options *options);
t_status	pft_get_pointer(va_list arg_ptr, t_options *options);
t_status	pft_get_string(va_list arg_ptr, t_options *options);
t_status	pft_get_unsigned(va_list arg_ptr, t_options *options);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
