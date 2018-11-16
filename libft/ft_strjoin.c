/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:51:52 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/22 18:51:54 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3 = ft_strnew(s1len + s2len);
	if (s3)
	{
		ft_memcpy(s3, s1, s1len);
		ft_memcpy(s3 + s1len, s2, s2len);
		s3[s1len + s2len] = '\0';
	}
	return (s3);
}
