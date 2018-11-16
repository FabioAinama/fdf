/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 15:50:31 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/20 15:50:33 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	get_center(t_fdf *fdf)
{
	int x_m;
	int y_m;
	int z_m;
	int cent_x;
	int cent_y;

	x_m = (fdf->map_width - 1) / 2;
	y_m = (fdf->map_height - 1) / 2;
	z_m = fdf->map[y_m][x_m] * fdf->zoom * fdf->zoom_height / 100;
	cent_x = (x_m - y_m) * fdf->zoom;
	cent_y = ((x_m + y_m) * fdf->zoom / fdf->inclinaison) - (z_m);
	fdf->center_x = (fdf->win_width / 2) - cent_x;
	fdf->center_y = (fdf->win_height / 2) - cent_y;
}

static	t_point	*create_point(int x, int y, t_fdf *fdf)
{
	t_point	*p1;
	int		z;

	if (!(p1 = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	p1->height = fdf->map[y][x];
	z = fdf->map[y][x] * fdf->zoom * fdf->zoom_height / 100;
	x *= fdf->zoom;
	y *= fdf->zoom;
	p1->x = x;
	p1->y = y;
	p1->z = z;
	p1->color = get_color(fdf, p1->height);
	if ((x >= 0) && (y >= 0))
	{
		iso_transformation(fdf, p1);
		y_rotation(fdf, p1);
		x_rotation(fdf, p1);
		p1->x += fdf->center_x;
		p1->y += fdf->center_y;
	}
	return (p1);
}

static	void	create_draw_segment(int col, int line, t_point *a, t_fdf *fdf)
{
	t_point	*b;

	if (!(b = create_point(col, line, fdf)))
	{
		free(a);
		exit_all_fdf(fdf);
	}
	draw_segment(a, b, fdf);
	free(b);
}

void			redraw_map(t_fdf *fdf)
{
	free_image(fdf);
	init_image(fdf);
	draw_map(fdf);
}

void			draw_map(t_fdf *fdf)
{
	t_point	*a;
	int		col;
	int		line;

	line = 0;
	get_center(fdf);
	while (line < fdf->map_height)
	{
		col = 0;
		while (col < fdf->map_width)
		{
			if (!(a = create_point(col, line, fdf)))
				exit_all_fdf(fdf);
			if ((col + 1) < fdf->map_width)
				create_draw_segment((col + 1), line, a, fdf);
			if (line > 0)
				create_draw_segment(col, (line - 1), a, fdf);
			free(a);
			col++;
		}
		line++;
	}
	mlx_put_image_to_window(fdf, fdf->win_ptr, fdf->im_ptr, 0, 0);
}
