/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:34:03 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:34:05 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = 0;
	while ((length += ft_wcharlen(src[i])) <= len)
	{
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
