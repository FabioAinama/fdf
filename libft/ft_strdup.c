/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:36:29 by fginja-d          #+#    #+#             */
/*   Updated: 2017/11/16 17:36:30 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		length;

	length = ft_strlen(s1);
	if (!(tmp = (char*)malloc((sizeof(char) * length) + 1)))
		return (NULL);
	return (ft_strcpy(tmp, s1));
}
