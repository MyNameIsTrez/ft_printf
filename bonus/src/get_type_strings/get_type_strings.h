/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_type_strings.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/28 17:35:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/28 18:47:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef GET_TYPE_STRINGS_H
# define GET_TYPE_STRINGS_H

////////////////////////////////////////////////////////////////////////////////

typedef struct s_options	t_options;

////////////////////////////////////////////////////////////////////////////////

char	*get_char(char **format, t_options *options);
char	*get_string(char **format, t_options *options);
char	*get_pointer(char **format, t_options *options);
char	*get_decimal(char **format, t_options *options);
char	*get_decimal(char **format, t_options *options);
char	*get_unsigned(char **format, t_options *options);
char	*get_hex_lower(char **format, t_options *options);
char	*get_hex_upper(char **format, t_options *options);
char	*get_percent(char **format, t_options *options);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
