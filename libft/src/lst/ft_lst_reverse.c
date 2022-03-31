/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_reverse.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/30 15:06:42 by sbos          #+#    #+#                 */
/*   Updated: 2022/03/29 14:48:08 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft.h"

////////////////////////////////////////////////////////////////////////////////

t_list	*ft_lst_reverse(t_list **lst)
{
	t_list	*cur;
	t_list	*prev;
	t_list	*next;

	cur = *lst;
	prev = NULL;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*lst = prev;
	return (*lst);
}

////////////////////////////////////////////////////////////////////////////////
