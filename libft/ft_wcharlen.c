/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:17:49 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:17:51 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcharlen(wchar_t wchar)
{
	int	length;

	length = 0;
	if (wchar <= 0xFF)
		length = 1;
	else if (wchar < 0x0800)
		length = 2;
	else if (wchar < 0x010000)
		length = 3;
	else if (wchar < 0x110000)
		length = 4;
	else
		length = -1;
	return (length);
}
