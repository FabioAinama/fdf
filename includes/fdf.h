/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:35:21 by fginja-d          #+#    #+#             */
/*   Updated: 2018/10/29 19:38:26 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef	struct	s_fdf
{
	int		fd1;
	int		fd2;
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	void	*im_ptr;
	char	*im_str;
	int		**map;
	int		inclinaison;
	int		center_x;
	int		center_y;
	int		offx;
	int		offy;
	float	y_radian;
	float	x_radian;
	int		zoom;
	int		zoom_height;
	int		color_mode;
	int		red;
	int		green;
	int		blue;
}				t_fdf;

typedef struct	s_point
{
	unsigned	int	color;
	int				red;
	int				green;
	int				blue;
	int				x;
	int				y;
	int				z;
	int				height;
}				t_point;

typedef	struct	s_segment
{
	int				ax;
	int				ay;
	int				az;
	int				a_h;
	int				bx;
	int				by;
	int				bz;
	int				b_h;
	int				dx;
	int				dy;
	int				d0;
	int				xpente;
	int				ypente;
	unsigned	int	a_color;
	unsigned	int	b_color;
}				t_segment;

void			base_values_fdf(t_fdf *fdf);
int				check_only_digits(char *str);
unsigned	int	choose_color(t_fdf *fdf, int z);
int				choose_z(t_segment *seg);
int				close_fdf(t_fdf *fdf);
int				del_line_return(char *line);
int				deal_offset(int key, t_fdf *fdf);
int				deal_radian(int key, t_fdf *fdf);
int				deal_zoom_height(int key, t_fdf *fdf);
void			draw_map(t_fdf *fdf);
int				draw_segment(t_point *a, t_point *b, t_fdf *fdf);
void			exit_all_fdf(t_fdf *fdf);
int				fill_fdf_map(t_fdf *fdf);
void			free_image(t_fdf *fdf);
unsigned	int	get_color(t_fdf *fdf, int z);
void			get_base_zoom(t_fdf *fdf);
int				get_map_options(t_fdf *fdf);
void			init_image(t_fdf *fdf);
void			iso_transformation(t_fdf *fdf, t_point *p1);
int				key_press(int key, t_fdf *fdf);
void			matrice_rotation(t_fdf *fdf, t_point *point);
void			mlx_destroy(t_fdf *fdf);
void			redraw_map(t_fdf *fdf);
void			y_rotation(t_fdf *fdf, t_point *point);
void			x_rotation(t_fdf *fdf, t_point *point);

#endif
