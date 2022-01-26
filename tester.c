/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:05:05 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/26 14:52:26 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "tests/tests.h"

////////////////////////////////////////////////////////////////////////////////

#include "bonus/src/ft_printf_bonus.h"

////////////////////////////////////////////////////////////////////////////////

#define TEST(test_function) {printf("Calling function '" #test_function "'\n");test_function();}

////////////////////////////////////////////////////////////////////////////////

void	run_tests(void)
{
	TEST(test_initialize_options);
	TEST(test_parse_flags);
	TEST(test_parse_field_width);
	// TEST(test_parse_precision);
	// TEST(test_fix_priorities);
	TEST(test_fill_options);
}

#include <unistd.h> // tmp
#include <fcntl.h> // tmp
#include <stdio.h> // tmp
#include <stdlib.h> // tmp
#include <assert.h> // tmp
#include <sys/mman.h> // tmp
void q(void)
{
	int *glob_var_0 = mmap(NULL, sizeof(*glob_var_0), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	int *glob_var_1 = mmap(NULL, sizeof(*glob_var_1), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	int ft_fd = open("/tmp/ft_printf_sbos", O_RDWR | O_CREAT, 0640);
	int fd = open("/tmp/printf_sbos", O_RDWR | O_CREAT, 0640);

	pid_t cpid = fork();
	if (cpid == 0)
	{
		dup2(ft_fd, STDOUT_FILENO);

		*glob_var_0 = ft_printf("hello %s", "world");
		*glob_var_1 = dprintf(fd, "hello %s", "world");

		close(ft_fd);
		close(fd);

		exit(EXIT_SUCCESS);
	}
	wait(NULL);

	size_t ft_out = (size_t)*glob_var_0;
	size_t out = (size_t)*glob_var_1;
	// ASSERT_INT((int)ft_out, (int)out);
	// dprintf(STDERR_FILENO, "ft_printf: %zu, printf: %zu\n", ft_out, out);

	lseek(ft_fd, 0, SEEK_SET);
	lseek(fd, 0, SEEK_SET);

	char ft_buf[ft_out * 2 + 1];
	ft_bzero(ft_buf, ft_out * 2 + 1);
	read(ft_fd, ft_buf, ft_out * 2);

	char buf[out + 1];
	buf[out] = '\0';
	read(fd, buf, out);
	ASSERT_STR(ft_buf, buf);
	// dprintf(STDERR_FILENO, "ft_printf: <%s>, printf: <%s>\n", ft_buf, buf);

	close(ft_fd);
	close(fd);

	munmap(glob_var_0, sizeof(glob_var_0));
	munmap(glob_var_1, sizeof(glob_var_1));
}

int	main(void)
{
	printf("Running tests...\n");
	run_tests();
	q();
	printf("Tests ran successfully!\n");
	return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
