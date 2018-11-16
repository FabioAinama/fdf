/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:29:58 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/22 18:30:00 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;

	i = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i] != '\0')
	{
		if ((s[i] != ' ' && s[i] != '\n' && s[i] != '\t') && (s[i + 1] == ' '
		|| s[i + 1] == '\n' || s[i + 1] == '\t' || s[i + 1] == '\0'))
			end = i + 1;
		i++;
	}
	len = (end == 0) ? (ft_strlen(s) - start) : (end - start);
	return (ft_strsub(s, start, len));
}
