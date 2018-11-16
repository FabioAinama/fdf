/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:34:40 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/09 15:34:42 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int un;

	un = n;
	if (n < 0)
	{
		ft_putchar('-');
		un = -n;
	}
	if (un > 9)
	{
		ft_putnbr(un / 10);
		ft_putchar(un % 10 + 48);
	}
	else
		ft_putchar(un + 48);
}
