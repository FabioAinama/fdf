/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:37:37 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/20 20:37:39 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		fill_pixel(t_fdf *fdf, int x, int y, unsigned int color)
{
	unsigned	int	*test;

	y += fdf->offy;
	x += fdf->offx;
	if (x < 0 || y < 0 || x >= fdf->win_width || y >= fdf->win_height)
		return ;
	test = (unsigned int *)fdf->im_str;
	test[y * fdf->win_width + x] = color;
}

static	t_segment	*init_segment(t_point *a, t_point *b)
{
	t_segment	*s;

	if (!(s = (t_segment*)malloc(sizeof(t_segment))))
		return (NULL);
	s->ax = a->x;
	s->ay = a->y;
	s->az = a->z;
	s->a_h = a->height;
	s->a_color = a->color;
	s->bx = b->x;
	s->by = b->y;
	s->bz = b->z;
	s->b_h = b->height;
	s->b_color = b->color;
	s->dx = (b->x > a->x) ? (b->x - a->x) : (a->x - b->x);
	s->dy = (b->y > a->y) ? (b->y - a->y) : (a->y - b->y);
	s->xpente = (a->x > b->x) ? -1 : 1;
	s->ypente = (a->y > b->y) ? -1 : 1;
	s->d0 = (s->dx < s->dy) ? (2 * s->dx - s->dy) : (2 * s->dy - s->dx);
	return (s);
}

static	void		draw_line_up(t_segment *seg, t_fdf *fdf)
{
	unsigned	int	color;
	int				z;

	z = choose_z(seg);
	color = choose_color(fdf, z);
	while (seg->ay != seg->by)
	{
		if (seg->d0 <= 0)
			seg->d0 += (2 * seg->dx);
		else
		{
			seg->d0 += 2 * (seg->dx - seg->dy);
			seg->ax += seg->xpente;
		}
		seg->ay += seg->ypente;
		fill_pixel(fdf, seg->ax, seg->ay, color);
	}
}

static	void		draw_line_down(t_segment *seg, t_fdf *fdf)
{
	unsigned	int	color;
	int				z;

	z = choose_z(seg);
	color = choose_color(fdf, z);
	while (seg->ax != seg->bx)
	{
		if (seg->d0 <= 0)
			seg->d0 += (2 * seg->dy);
		else
		{
			seg->d0 += 2 * (seg->dy - seg->dx);
			seg->ay += seg->ypente;
		}
		seg->ax += seg->xpente;
		fill_pixel(fdf, seg->ax, seg->ay, color);
	}
}

int					draw_segment(t_point *a, t_point *b, t_fdf *fdf)
{
	t_segment		*seg;
	unsigned	int	color;

	color = choose_color(fdf, a->height);
	if (!(seg = init_segment(a, b)))
	{
		free(a);
		free(b);
		exit_all_fdf(fdf);
	}
	fill_pixel(fdf, a->x, a->y, color);
	if (seg->dx < seg->dy)
		draw_line_up(seg, fdf);
	else
		draw_line_down(seg, fdf);
	free(seg);
	return (0);
}
