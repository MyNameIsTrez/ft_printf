/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   experiment.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:04:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/17 14:55:12 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	s(void);
void	d(void);
void	c(void);

typedef void	(*t_jump_function)(void);

const t_jump_function	*get_jump_table(void)
{
	const static t_jump_function	jump_table[] = {
	['s'] = s,
	['d'] = d,
	['c'] = c
	};

	return (jump_table);
}

void	s(void)
{
	printf("s() was called\n");
}

void	d(void)
{
	printf("d() was called\n");
}

void	c(void)
{
	printf("c() was called\n");
}

int	main(void)
{
	int						input;
	const t_jump_function	*jump_table = get_jump_table();

	input = 'd';
	jump_table[input]();
	return (EXIT_SUCCESS);
}
