/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:39:23 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/08 18:05:25 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ANGLE_ISO 0.523
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct draw t_draw;
typedef struct matrice t_matrice;

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		largeur_max;
	int		hauteur_max;
	int		img_largeur_max;
	int		img_hauteur_max;
	int		img_bits_pixel;
	t_draw	*drw;
	t_matrice *cor;
}			t_mlx;

typedef struct matrice
{
	int		x_max;
	int		y_max;
	int		**matrice;
	int		ligne;
	int		colonne;
}			t_matrice;

typedef struct bresenham
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;
}			t_brs;

typedef struct draw
{
	int		x;
	int		y;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int 	z0;
	int		z1;
	int		color;
	t_mlx	*mlx;
}			t_draw;


// map.c
void		map_coord(t_matrice *cor, char *file);
void		check_map(t_matrice *cor, char *file);
int			copi_matrice(t_matrice *cor, char *file);
// draw.c
void 	draw_lines(t_draw *drw, t_matrice *cor);
void		draw_calcul(t_draw *drw, t_matrice *cor);
void		draw_horizontale(t_draw *drw, t_matrice *cor);
void		draw_verticale(t_draw *drw, t_matrice *cor);
void    	draw_isometric(int *x, int *y, int z);
// bresenham.c
void 		bresenham(t_draw *drw, t_mlx *mlx);
void    	little_bresenham(t_brs *brs, t_draw *drw);
// centre.c
void		center_image(t_mlx *mlx);

#endif
