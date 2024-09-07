/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 23:39:23 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/07 19:03:00 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		largeur_max;
	int		hauteur_max;
	int		img_largeur_max;
	int		img_hauteur_max;
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
    int     dx;
    int     dy;
    int	    sx;
	int	    sy;
	int	    error;
	int	    e2;
}   		t_brs;

// map.c
void		map_coord(t_matrice *cor, char *file);
void		check_map(t_matrice *cor, char *file);
int			copi_matrice(t_matrice *cor, char *file);
// draw.c
void    draw_lines(t_matrice *cor, t_mlx *mlx);
// bresenham.c
void	bresenham(int x0, int y0, int x1, int y1, t_mlx *mlx);

#endif
