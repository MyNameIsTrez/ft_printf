/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_type_strings.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 17:35:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/01 16:55:32 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef GET_TYPE_STRINGS_H
# define GET_TYPE_STRINGS_H

////////////////////////////////////////////////////////////////////////////////

# include <stdarg.h>	// va_list

////////////////////////////////////////////////////////////////////////////////

typedef struct s_options	t_options;

////////////////////////////////////////////////////////////////////////////////

char	*get_char(t_options *options, va_list *arg_ptr);
char	*get_string(t_options *options, va_list *arg_ptr);
char	*get_pointer(t_options *options, va_list *arg_ptr);
char	*get_decimal(t_options *options, va_list *arg_ptr);
char	*get_unsigned(t_options *options, va_list *arg_ptr);
char	*get_hex_lower(t_options *options, va_list *arg_ptr);
char	*get_hex_upper(t_options *options, va_list *arg_ptr);
char	*get_percent(t_options *options, va_list *arg_ptr);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
