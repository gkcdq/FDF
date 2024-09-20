/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:22:23 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/18 18:52:38 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_h
# define FDF_h
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define ANGLE 0.523599
# define IMG_HAUTEUR_MAX 20
# define IMG_LARGEUR_MAX 20
# define LARGEUR 1920
# define HAUTEUR 1080
# define NOIR 0x0
# define GRIS 0xbebebe
# define BLANC 0xFFFFFF
# define ROUGE 0xFF0000
# define ROUGE_ORANGE 0xFF4500
# define ORANGE 0xFFA500
# define VERT_ORANGE 0x2e8b57
# define JAUNE_ORANGE 0xFFD700
# define JAUNE 0xFFFF00
# define VERT_JAUNE 0xADFF2F
# define VERT 0x008000
# define BLEU_VERT 0x00CED1
# define BLEU 0x5f9ea0
# define VIOLET 0x8A2BE2

typedef struct data	t_data;
typedef struct bresenham	t_brs;
typedef struct draw			t_draw;
typedef struct mlx			t_mlx;

typedef struct data
{
	int						x;
	int						y;
	int						x_max;
	int						y_max;
	int						**final_tab;
}							t_data;

typedef struct bresenham
{
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						error;
	int						e2;
}							t_brs;

typedef struct draw
{
	int						x;
	int						y;
	int						x0;
	int						y0;
	int						z0;
	int						x1;
	int						y1;
	int						z1;
	int						offset_x;
	int						offset_y;
	double					scale_x;
	double					scale_y;
	double					scale_z;
	t_data					*cor;
	t_brs					*brs;
	t_mlx					*mlx;
}							t_draw;

typedef struct mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	int						line_length;
	int						bits_per_pixel;
	int						size_line;
	char					*addr;
	int						endian;
	t_draw					*drw;
	t_data					*cor;
}							t_mlx;
// map.c
void						map_mesure(t_data *cor, char *file);
void						check_matrice(t_data *cor, char *file);
void						copi_matrice(t_data *cor, char *file);

// draw.c
void						draw_horizontale(t_draw *drw, t_data *cor);
void						draw_verticale(t_draw *drw, t_data *cor);
void						draw_calcul(t_draw *drw, t_data *cor);
void						draw_lines(t_draw *drw, t_data *cor);
void						draw_isometrique(int *x, int *y, int z);


// ft_scale.c
double						ft_scale(t_data *cor);
double						scale_x(t_draw *drw, t_data *cor);
double						scale_y(t_draw *drw, t_data *cor);

// bresenham.c
void 						little_bresenham(t_brs *brs, t_draw *drw);
void						bresenham(t_draw *drw);

// pixel_and_color.c
void						draw_pixel(t_mlx *mlx, int x, int y, int z);
unsigned int				color_pxl(int z);

// define.c
void						define_cor(t_data *cor);
void						define_draw(t_draw *drw);
void						define_points_start(t_draw *drw, t_data *cor);

#endif