/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   EXTRA_ft_lst_new_front.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/09 16:33:32 by sbos          #+#    #+#                 */
/*   Updated: 2021/11/09 16:44:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_new_front(t_list **lst, void *content)
{
	ft_lstadd_front(lst, ft_lstnew(content));
}