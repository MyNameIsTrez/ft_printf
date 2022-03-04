/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   advanced_printf_tester.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:14:55 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/04 16:49:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include <unistd.h> // tmp
#include <fcntl.h> // tmp
#include <stdio.h> // tmp
#include <stdlib.h> // tmp
#include <assert.h> // tmp
#include <sys/mman.h> // tmp

////////////////////////////////////////////////////////////////////////////////

static long	get_file_size(int fd)
{
	FILE *f = fdopen(fd, "rw");

	fseek(f, 0, SEEK_END);
	return (ftell(f));
}

////////////////////////////////////////////////////////////////////////////////

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

	massert((int)ft_printf_return, (int)file_size); // check if return value correct with output
	massert((int)ft_printf_return, (int)printf_return); // check if return value correct
	massert(ft_buf, buf);
}

////////////////////////////////////////////////////////////////////////////////
