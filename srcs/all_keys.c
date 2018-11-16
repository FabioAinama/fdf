/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:18:20 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/25 17:18:22 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_offset(int key, t_fdf *fdf)
{
	if (key == 13)
		fdf->offy += 24;
	else if (key == 1)
		fdf->offy -= 24;
	else if (key == 2)
		fdf->offx -= 36;
	else if (key == 0)
		fdf->offx += 36;
	else if (key == 87)
	{
		fdf->offx = 0;
		fdf->offy = 0;
	}
	else
		return (0);
	return (1);
}

int	deal_radian(int key, t_fdf *fdf)
{
	if (key == 91 || key == 89 || key == 92)
		fdf->x_radian += 0.02;
	if (key == 84 || key == 83 || key == 85)
		fdf->x_radian -= 0.02;
	if (key == 86 || key == 89 || key == 83)
		fdf->y_radian += 0.02;
	if (key == 88 || key == 92 || key == 85)
		fdf->y_radian -= 0.02;
	if (key >= 83 && key <= 92 && key != 87 && key != 90)
		return (1);
	return (0);
}

int	deal_zoom_height(int key, t_fdf *fdf)
{
	if (key == 75 && fdf->zoom_height > 1)
		fdf->zoom_height--;
	else if (key == 67)
		fdf->zoom_height++;
	else if (key == 69)
	{
		if (fdf->zoom >= 10)
			fdf->zoom += 2;
		else
			fdf->zoom += 1;
	}
	else if (key == 78 && fdf->zoom > 1)
	{
		if (fdf->zoom >= 10)
			fdf->zoom -= 2;
		else
			fdf->zoom -= 1;
	}
	else
		return (0);
	return (1);
}
