/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:50:46 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/22 15:50:47 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_tostr(char *str, long int nb, size_t signe, size_t length)
{
	size_t		tmp;

	if (signe)
		str[0] = '-';
	while (length > 0)
	{
		tmp = nb;
		if (tmp >= 10)
			tmp = tmp % 10;
		str[length + signe - 1] = tmp + 48;
		nb /= 10;
		length--;
	}
}

char			*ft_itoa(int n)
{
	long int	nb;
	size_t		signe;
	size_t		length;
	char		*str;

	signe = (((long)n < 0) ? (1) : 0);
	nb = (((long)n < 0) ? (-(long)n) : (long)n);
	length = 1;
	while ((n /= 10))
		length++;
	str = ft_strnew(length + signe);
	if (str == NULL)
		return (NULL);
	ft_tostr(str, nb, signe, length);
	return (str);
}
