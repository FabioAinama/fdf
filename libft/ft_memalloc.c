/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:52:07 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/18 18:52:10 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = NULL;
	if (size)
	{
		str = (void *)malloc(sizeof(str) * size);
		if (!str)
			return (NULL);
		ft_bzero(str, size);
	}
	return (str);
}
