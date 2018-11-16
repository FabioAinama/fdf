/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:24:39 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/13 17:24:41 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;
	size_t	i;
	size_t	maxlen;

	needlen = ft_strlen(needle);
	i = 0;
	if (len >= needlen)
		maxlen = needlen;
	else
		return (NULL);
	if (*needle == '\0' || needlen == 0)
		return ((char*)haystack);
	while (*haystack != '\0' && (i + maxlen <= len) && len > 0)
	{
		if (!ft_memcmp(haystack, needle, maxlen))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
