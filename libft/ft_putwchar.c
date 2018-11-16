/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:24:22 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:24:25 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert_wchar(wchar_t wchar, char *converted)
{
	int	length;

	length = 0;
	if (wchar <= 0xFF)
		converted[length++] = wchar;
	else if (wchar < 0x0800)
	{
		converted[length++] = ((wchar >> 6) & 0x1F) | 0xC0;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x010000)
	{
		converted[length++] = ((wchar >> 12) & 0x0F) | 0xE0;
		converted[length++] = ((wchar >> 6) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
	{
		converted[length++] = ((wchar >> 18) & 0x07) | 0xF0;
		converted[length++] = ((wchar >> 12) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 6) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	return (length);
}

int	ft_putwchar(wchar_t wchar)
{
	char	converted[4];
	int		length;

	length = ft_convert_wchar(wchar, converted);
	write(1, converted, length);
	return (length);
}
