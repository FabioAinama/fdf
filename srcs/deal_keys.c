/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:41:32 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/29 19:48:53 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	color_keys(int key, t_fdf *fdf)
{
	if (key == 36)
		fdf->color_mode = !(fdf->color_mode);
	else if (key == 15 && fdf->red < 255)
		fdf->red += 10;
	else if (key == 17 && fdf->red > 5)
		fdf->red -= 10;
	else if (key == 5 && fdf->green < 255)
		fdf->green += 10;
	else if (key == 4 && fdf->green > 5)
		fdf->green -= 10;
	else if (key == 11 && fdf->blue < 255)
		fdf->blue += 10;
	else if (key == 45 && fdf->blue > 5)
		fdf->blue -= 10;
	else
		return (0);
	return (1);
}

int			close_fdf(t_fdf *fdf)
{
	mlx_destroy(fdf);
	exit_all_fdf(fdf);
	return (0);
}

int			key_press(int key, t_fdf *fdf)
{
	int	dealed_key;

	dealed_key = 0;
	if (key == 53)
	{
		mlx_destroy(fdf);
		exit_all_fdf(fdf);
	}
	dealed_key += color_keys(key, fdf);
	dealed_key += deal_zoom_height(key, fdf);
	dealed_key += deal_offset(key, fdf);
	dealed_key += deal_radian(key, fdf);
	if (dealed_key > 0)
		redraw_map(fdf);
	return (0);
}
