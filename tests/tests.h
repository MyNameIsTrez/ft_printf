/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 11:42:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/01 17:54:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#ifndef TESTS_H
# define TESTS_H

////////////////////////////////////////////////////////////////////////////////

# include "../bonus/src/ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

# include <stdio.h>		// printf()
# include <stdlib.h>	// EXIT_SUCCESS
# include <assert.h>	// assert()
# include <string.h>	// strcmp()

////////////////////////////////////////////////////////////////////////////////

#define ASSERT_INT(a, b) {					\
	char *tested_var = #a;					\
	(void)tested_var;						\
											\
	int tested_value = a;					\
											\
	char *expected_var = #b;				\
	(void)expected_var;						\
											\
	int expected_value = b;					\
											\
	assert(tested_value == expected_value);	\
}

#define ASSERT_CHAR(a, b) {					\
	char *tested_var = #a;					\
	(void)tested_var;						\
											\
	char tested_value = a;					\
											\
	char *expected_var = #b;				\
	(void)expected_var;						\
											\
	char expected_value = b;				\
											\
	assert(tested_value == expected_value);	\
}

#define ASSERT_BOOL(a, b) {					\
	char *tested_var = #a;					\
	(void)tested_var;						\
											\
	bool tested_value = a;					\
											\
	char *expected_var = #b;				\
	(void)expected_var;						\
											\
	bool expected_value = b;				\
											\
	assert(tested_value == expected_value);	\
}

#define ASSERT_STR(a, b) {								\
	char *tested_var = #a;								\
	(void)tested_var;									\
														\
	char *tested_value = a;								\
														\
	char *expected_var = #b;							\
	(void)expected_var;									\
														\
	char *expected_value = b;							\
														\
	assert(strcmp(tested_value, expected_value) == 0);	\
}

////////////////////////////////////////////////////////////////////////////////

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

void	test_get_char(void);

////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////
