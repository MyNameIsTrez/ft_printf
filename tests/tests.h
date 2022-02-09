/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/09 14:47:25 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef TESTS_H
# define TESTS_H

////////////////////////////////////////////////////////////////////////////////

# include "ft_printf_bonus.h"

# include "test_get_type_strings.h"

# include "asserts.h"

////////////////////////////////////////////////////////////////////////////////

// TODO: Why the hell are the regular functions declared here as well?

void	initialize_options(t_options *options);
void	test_initialize_options(void);

void	parse_flags(const char **format, t_options *options);
void	test_parse_flags(void);

void	parse_field_width(const char **format, t_options *options);
void	test_parse_field_width(void);

void	parse_precision(const char **format, t_options *options);
void	test_parse_precision(void);

void	fix_priorities(t_options *options);
void	test_fix_priorities(void);

void	fill_options(const char **format, t_options *options);
void	test_fill_options(void);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
