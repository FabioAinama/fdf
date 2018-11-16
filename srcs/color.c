/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:55:36 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/22 18:55:38 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				choose_z(t_segment *seg)
{
	if (seg->a_h >= seg->b_h)
		return (seg->a_h);
	else
		return (seg->b_h);
}

unsigned	int	choose_color(t_fdf *fdf, int z)
{
	unsigned	int	color;

	if (fdf->color_mode == 0)
	{
		color = (fdf->red & 0xff) << 16;
		color += (fdf->green & 0xff) << 8;
		color += (fdf->blue & 0xff);
	}
	else
		color = get_color(fdf, z);
	return (color);
}

unsigned	int	get_color(t_fdf *fdf, int z)
{
	(void)fdf;
	if (z > 0)
		return (0x7CFF00);
	else if (z < 0)
		return (0x0F006D);
	else
		return (0x2200FF);
}
