/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/04 18:33:00 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests/tests.h"

////////////////////////////////////////////////////////////////////////////////

#include "bonus/src/ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#define TEST(test_function) {printf("Calling function '" #test_function "'\n");test_function();}

////////////////////////////////////////////////////////////////////////////////

void	test_fill_options_and_subfunctions(void)
{
	TEST(test_initialize_options);
	TEST(test_parse_flags);
	TEST(test_parse_field_width);
	TEST(test_parse_precision);
	TEST(test_fix_priorities);
	TEST(test_fill_options);
}

void	test_get_type_strings(void)
{
	TEST(test_get_char);
	TEST(test_get_decimal);
	TEST(test_get_hex_lower);
	TEST(test_get_hex_upper);
}

////////////////////////////////////////////////////////////////////////////////

void	run_tests(void)
{
	test_fill_options_and_subfunctions();
	test_get_type_strings();
}

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // tmp
#include <fcntl.h> // tmp
#include <stdio.h> // tmp
#include <stdlib.h> // tmp
#include <assert.h> // tmp
#include <sys/mman.h> // tmp
long	get_file_size(int fd)
{
	FILE *f = fdopen(fd, "rw");

	fseek(f, 0, SEEK_END);
	return (ftell(f));
}

void q(void)
{
	int *glob_var_0 = mmap(NULL, sizeof(*glob_var_0), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int *glob_var_1 = mmap(NULL, sizeof(*glob_var_1), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	int ft_printf_fd = open("/tmp/ft_printf_sbos", O_RDWR | O_CREAT, 0640);
	int printf_fd = open("/tmp/printf_sbos", O_RDWR | O_CREAT, 0640);

	pid_t cpid = fork();
	if (cpid == 0)
	{
		dup2(ft_printf_fd, STDOUT_FILENO);

		*glob_var_0 = ft_printf("hello %s", "world");
		*glob_var_1 = dprintf(printf_fd, "hello %s", "world");

		close(ft_printf_fd);
		close(printf_fd);

		exit(EXIT_SUCCESS);
	}
	wait(NULL);

	size_t ft_printf_return = (size_t)*glob_var_0;
	size_t printf_return = (size_t)*glob_var_1;

	long file_size = get_file_size(ft_printf_fd);

	lseek(ft_printf_fd, 0, SEEK_SET);
	lseek(printf_fd, 0, SEEK_SET);

	char ft_buf[file_size + 1];
	ft_bzero(ft_buf, (size_t)file_size + 1);
	read(ft_printf_fd, ft_buf, (size_t)file_size);

	char buf[printf_return + 1];
	buf[printf_return] = '\0';
	read(printf_fd, buf, printf_return);

	close(ft_printf_fd);
	close(printf_fd);

	munmap(glob_var_0, sizeof(glob_var_0));
	munmap(glob_var_1, sizeof(glob_var_1));

	ASSERT_INT((int)ft_printf_return, (int)file_size); // check if return value correct with output
	ASSERT_INT((int)ft_printf_return, (int)printf_return); // check if return value correct
	ASSERT_STR(ft_buf, buf);
}

////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	printf("Running tests...\n");
	run_tests();
	// q();
	printf("Tests ran successfully!\n");
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
