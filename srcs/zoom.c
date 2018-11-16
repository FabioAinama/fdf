/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:13:10 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/22 13:13:11 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_base_zoom(t_fdf *fdf)
{
	int zoom;
	int max_w;
	int max_h;

	zoom = 0;
	max_w = (fdf->win_width / fdf->map_width) / 1.5;
	max_h = (fdf->win_height / fdf->map_height) / 1.5;
	fdf->zoom = (max_h > max_w ? max_w : max_h);
}
