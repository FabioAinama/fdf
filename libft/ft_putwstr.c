/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:09:05 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:09:08 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *wstr)
{
	size_t	length;

	length = 0;
	while (*wstr)
	{
		ft_putwchar(*wstr);
		length += ft_wcharlen(*wstr);
		wstr += 1;
	}
	return (length);
}
