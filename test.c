/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/15 13:04:53 by sbos          #+#    #+#                 */
/*   Updated: 2022/01/15 17:11:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list	t_list;

struct s_list
{
	void	*content;
};

int	main(void)
{
	t_list	*lists[2];
	t_list	*list;

	lists[0] = NULL;
	lists[1] = malloc(sizeof(t_list));
	lists[1]->content = strdup("foo");
	list = lists[1];
	printf("%s\n", (char *)list->content);
	printf("%p\n", list);
	return (EXIT_SUCCESS);
}
