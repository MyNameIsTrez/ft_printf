/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/23 17:26:40 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef TESTS_H
# define TESTS_H

////////////////////////////////////////////////////////////////////////////////

# include "ft_printf_bonus.h"

# include "test_get_type_strings.h"

# include "massert.h"

////////////////////////////////////////////////////////////////////////////////

typedef void (*void_fn)(void);

typedef struct s_fn_info {
	char	*fn_name;
	void_fn	fn_ptr;
}	t_fn_info;

////////////////////////////////////////////////////////////////////////////////

extern t_list	*g_tests_lst;

////////////////////////////////////////////////////////////////////////////////

#define Test(name)																\
	void test_##name(void);														\
	__attribute__((constructor))												\
	void add_test_##name(void)													\
	{																			\
		static t_fn_info fn_info = {.fn_name = #name, .fn_ptr = &test_##name};	\
		ft_lst_new_front(&g_tests_lst, &fn_info);								\
	}																			\
	void test_##name(void)

////////////////////////////////////////////////////////////////////////////////
// These are helper functions from bonus/src
// that aren't in bonus/src/ft_printf_bonus.h as they are normally private.

void	parse_format(const char **format, t_conversion *conversion);
void	fix_priorities(t_conversion *conversion);
const t_conversion_function	*get_conversion_table(void);
void	initialize_state(t_conversion *conversion);
void	parse_argument(t_conversion *conversion, va_list arg_ptr);
void	parse_field_width(const char **format, t_conversion *conversion);
void	parse_flags(const char **format, t_conversion *conversion);
void	parse_precision(const char **format, t_conversion *conversion);
void	parse_conversion_type(const char **format, t_conversion *conversion);
void	apply_precision(t_conversion *conversion);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
