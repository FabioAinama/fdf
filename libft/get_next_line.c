/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:16:20 by fginja-d          #+#    #+#             */
/*   Updated: 2018/01/30 11:16:22 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_text_pointer(char **str, const int fd)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*str)
			*str = ft_strdup(buf);
		else
		{
			if (!(tmp = ft_strdup(*str)))
				return (0);
			ft_strdel(str);
			if (!(*str = ft_strjoin(tmp, buf)))
				return (0);
			ft_strdel(&tmp);
		}
	}
	return (ret == -1 ? 0 : 1);
}

static	int	return_one_line(char *str, char **line, char **tab_string)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (!(*line = ft_strsub(str, 0, i)))
				return (0);
			tmp = ft_strsub(str, i + 1, ft_strlen(str));
			ft_strdel(&str);
			if (!(str = (!tmp ? NULL : ft_strdup(tmp))))
				return (0);
			ft_strdel(&tmp);
			if (!(*tab_string = ft_strdup(str)))
				return (0);
			ft_strdel(&str);
			return (1);
		}
		i++;
	}
	*line = ft_strdup(str);
	ft_strdel(tab_string);
	return (i == 0 ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*tab[OPEN_MAX];
	int				i;

	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (!(ft_text_pointer(&tab[fd], fd)))
		return (-1);
	if (tab[fd] == NULL)
		return (0);
	i = return_one_line(tab[fd], line, &tab[fd]);
	if (!(*line))
		return (0);
	return (i);
}
