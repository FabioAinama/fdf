/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:25:36 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/22 21:25:37 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_transformation(t_fdf *fdf, t_point *p1)
{
	int	previous_x;
	int	previous_y;

	(void)fdf;
	previous_x = p1->x;
	previous_y = p1->y;
	p1->x = (previous_x - previous_y) * cos(0.523599);
	p1->y = (previous_x + previous_y) * sin(0.523599) - p1->z;
}

void	y_rotation(t_fdf *fdf, t_point *point)
{
	float	coss;
	float	sinn;
	int		x;
	int		y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;
	coss = cos(fdf->y_radian);
	sinn = sin(fdf->y_radian);
	point->x = (x * coss + z * sinn);
	point->z = (-x * sinn + z * coss);
}

void	x_rotation(t_fdf *fdf, t_point *point)
{
	float	coss;
	float	sinn;
	int		x;
	int		y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;
	coss = cos(fdf->x_radian);
	sinn = sin(fdf->x_radian);
	point->y = (y * coss + z * sinn);
	point->z = (z * coss - y * sinn);
}
