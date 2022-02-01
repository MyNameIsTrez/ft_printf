/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 12:39:55 by sbos          #+#    #+#                 */
/*   Updated: 2021/11/25 18:20:17 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

/**
 * @brief Allocates and returns a substring from the string @p str.\n
   The substring begins at index @p start and is of maximum length @p len.
 *
 * @param str 💥 The string from which to create the substring.
 * @param start The start index of the substring in the string @p str.
 * @param len The maximum length of the substring.
 * @return The substring;\n
   NULL if the allocation fails.
 */
char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	new_len;

	if (str == NULL)
		return (NULL);
	if (ft_strlen(str) <= start)
		return (ft_strdup(""));
	new_len = ft_strnlen(&str[start], len);
	substr = malloc((new_len + 1) * sizeof(char));
	if (substr != NULL)
	{
		// TODO: Use strlcpy()
		substr[new_len] = '\0';
		ft_memcpy(substr, &str[start], new_len);
	}
	return (substr);
}