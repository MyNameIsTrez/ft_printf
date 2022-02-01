/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rejoin_split.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/10 17:14:08 by sbos          #+#    #+#                 */
/*   Updated: 2021/11/25 18:16:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_rejoined_len(char **split, size_t sep_len)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (split[i] != NULL)
	{
		if (split[i][0] == '\0')
			len += sep_len;
		else
			len += ft_strlen(split[i]);
		i++;
	}
	return (len);
}

static void	fill_rejoin(char *rejoined, char **split, char *sep
					, size_t rejoined_len)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
	{
		if (split[i][0] == '\0')
			ft_strlcat(rejoined, sep, rejoined_len + 1);
		else
			ft_strlcat(rejoined, split[i], rejoined_len + 1);
		i++;
	}
}

char	*ft_rejoin_split(char **split, char *sep)
{
	const size_t	sep_len = ft_strlen(sep);
	char			*rejoined;
	size_t			rejoined_len;

	rejoined_len = get_rejoined_len(split, sep_len);
	rejoined = ft_stralloc(rejoined_len);
	if (rejoined != NULL)
		fill_rejoin(rejoined, split, sep, rejoined_len);
	return (rejoined);
}