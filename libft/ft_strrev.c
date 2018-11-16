/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:44:43 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 12:44:45 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(str) - 1;
	while (i < (length - i))
	{
		tmp = str[i];
		str[i] = str[(length) - i];
		str[(length) - i] = tmp;
		i++;
	}
	return (str);
}
