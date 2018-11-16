/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:03:39 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/15 20:03:41 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char *tmp;

	tmp = src;
	if (dst > src)
	{
		while (len != 0)
		{
			((char*)dst)[len - 1] = ((char*)tmp)[len - 1];
			len--;
		}
	}
	if (dst < src)
		ft_memcpy(dst, src, len);
	return (dst);
}
