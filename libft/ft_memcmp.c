/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:26:18 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/16 16:26:21 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	s1bis;
	unsigned char	s2bis;

	i = 0;
	while (i < n)
	{
		s1bis = *(unsigned char *)s1;
		s2bis = *(unsigned char *)s2;
		if (s1bis != s2bis)
			return (s1bis - s2bis);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
