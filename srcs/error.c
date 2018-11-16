/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:55:52 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/29 19:50:11 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_destroy(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->im_ptr = NULL;
	fdf->im_str = NULL;
	fdf->mlx_ptr = NULL;
}

int		check_only_digits(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		del_line_return(char *line)
{
	ft_strdel(&line);
	return (0);
}

void	exit_all_fdf(t_fdf *fdf)
{
	int i;

	i = -1;
	if (fdf->mlx_ptr != NULL)
		free(fdf->mlx_ptr);
	if (fdf->im_ptr != NULL)
		free(fdf->im_ptr);
	if (fdf->im_str != NULL)
		free(fdf->im_str);
	if (fdf->map != NULL)
	{
		while (++i < fdf->map_height)
			free(fdf->map[i]);
		free(fdf->map);
	}
	if (fdf->fd1 > 2)
		close(fdf->fd1);
	if (fdf->fd2 > 2)
		close(fdf->fd2);
	exit(0);
}
