/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_type_strings.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 17:35:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:26:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef GET_TYPE_STRINGS_H
# define GET_TYPE_STRINGS_H

////////////////////////////////////////////////////////////////////////////////

# include <stdarg.h>	// va_list

////////////////////////////////////////////////////////////////////////////////

typedef struct s_conversion	t_conversion;

////////////////////////////////////////////////////////////////////////////////

void	get_char(va_list arg_ptr, t_conversion *conversion);
void	get_decimal(va_list arg_ptr, t_conversion *conversion);
void	get_hex_lower(va_list arg_ptr, t_conversion *conversion);
void	get_hex_upper(va_list arg_ptr, t_conversion *conversion);
void	get_percent(va_list arg_ptr, t_conversion *conversion);
void	get_pointer(va_list arg_ptr, t_conversion *conversion);
void	get_string(va_list arg_ptr, t_conversion *conversion);
void	get_unsigned(va_list arg_ptr, t_conversion *conversion);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
