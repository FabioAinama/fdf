/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:37:19 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/28 16:37:22 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
		words++;
	}
	return (words);
}

static void	ft_start_end(char **ptr, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i != start)
			ptr[j++] = ft_strsub(s, start, (i - start));
	}
	ptr[j] = 0;
}

char		**ft_strsplit(const char *s, char c)
{
	char	**ptr;

	if (s && (ptr = (char **)malloc(sizeof(*ptr) * (ft_count_words(s, c) + 1))))
	{
		ft_start_end(ptr, s, c);
		return (ptr);
	}
	return (NULL);
}
