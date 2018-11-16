/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:34:08 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/29 19:47:12 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			free_image(t_fdf *fdf)
{
	free(fdf->im_ptr);
	fdf->im_ptr = NULL;
	free(fdf->im_str);
	fdf->im_str = NULL;
}

void			init_image(t_fdf *fdf)
{
	int	bpp;
	int	s_l;
	int	endian;

	fdf->im_ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_height);
	if (!(fdf->im_ptr))
		exit_all_fdf(fdf);
	fdf->im_str = mlx_get_data_addr(fdf->im_ptr, &(bpp), &(s_l), &(endian));
	if (!(fdf->im_str))
		exit_all_fdf(fdf);
}

static	void	init_fdf(t_fdf *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()))
		exit_all_fdf(fdf);
	get_base_zoom(fdf);
	fdf->zoom_height = 4;
	init_image(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width,
		fdf->win_height, "42 fdf");
	if (!(fdf->win_ptr))
		exit_all_fdf(fdf);
}

int				main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (0);
	if (ft_strstr(argv[1], ".fdf") == NULL)
		return (0);
	if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	base_values_fdf(fdf);
	if ((fdf->fd1 = open(argv[1], O_RDONLY)) == -1
		|| (fdf->fd2 = open(argv[1], O_RDONLY)) == -1)
		exit_all_fdf(fdf);
	if (get_map_options(fdf) == 0)
		exit_all_fdf(fdf);
	if (fill_fdf_map(fdf) == 0)
		exit_all_fdf(fdf);
	init_fdf(fdf);
	draw_map(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_fdf, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
