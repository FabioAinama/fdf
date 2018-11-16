/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 14:34:14 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/29 19:45:24 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			base_values_fdf(t_fdf *fdf)
{
	fdf->map_width = -1;
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->im_ptr = NULL;
	fdf->im_str = NULL;
	fdf->map = NULL;
	fdf->win_width = 1800;
	fdf->win_height = 1200;
	fdf->offx = 0;
	fdf->offy = 0;
	fdf->zoom = 5;
	fdf->inclinaison = 2;
	fdf->y_radian = 6.28;
	fdf->x_radian = 5.66;
	fdf->color_mode = 0;
	fdf->red = 15;
	fdf->green = 15;
	fdf->blue = 15;
}

static	int		get_length_line(char *line)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	return (i);
}

static	int		fill_fdf_map_line(t_fdf *fdf, char *line, int j)
{
	char	**tab;
	int		i;
	int		error;
	int		nb;

	i = 0;
	error = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		return (1);
	while (tab[i])
	{
		nb = ft_atol(tab[i]);
		if (nb > INT_MAX || check_only_digits(tab[i]) == 0 || nb < INT_MIN)
			error = 1;
		fdf->map[j][i] = nb;
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	return (error);
}

int				fill_fdf_map(t_fdf *fdf)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!(fdf->map = (int **)malloc(sizeof(int *) * fdf->map_height)))
		return (0);
	while (get_next_line(fdf->fd2, &line) > 0)
	{
		if (line == NULL)
			return (0);
		if (!(fdf->map[i] = (int *)malloc(sizeof(int) * fdf->map_width)))
			return (del_line_return(line));
		if (fill_fdf_map_line(fdf, line, i) == 1)
			return (del_line_return(line));
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	return (1);
}

int				get_map_options(t_fdf *fdf)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (get_next_line(fdf->fd1, &line) > 0)
	{
		if (line == NULL)
			return (0);
		if (fdf->map_width == -1)
			if ((fdf->map_width = get_length_line(line)) == -1)
				return (del_line_return(line));
		if (get_length_line(line) != fdf->map_width)
			return (del_line_return(line));
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	fdf->map_height = i;
	return (i);
}
