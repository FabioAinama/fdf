/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:32:42 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:32:44 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *src)
{
	int		length;
	wchar_t	*dst;

	length = ft_wstrlen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * length);
	if (dst)
		ft_wstrcpy(dst, src);
	return (dst);
}
