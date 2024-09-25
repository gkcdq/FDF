/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:26 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/25 21:36:57 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_draw *drw, t_data *cor)
{
	draw_calcul(*drw, cor);
	ft_putendl_fd("Dessin complet!", 1);
}

void	draw_calcul(t_draw drw, t_data *cor)
{
	drw.scale_z = ft_scale(cor);
	drw.y = -1;
	while (++drw.y < cor->y_max)
	{
		drw.x = -1;
		while (++drw.x < cor->x_max)
		{
			define_points_start(&drw, cor);
			draw_isometrique(&drw.x0, &drw.y0, drw.z0);
			if (drw.x + 1 < cor->x_max)
			{
				draw_horizontale(drw, cor);
			}			
			if (drw.y + 1 < cor->y_max)
			{
				draw_verticale(drw, cor);
			}
		}
	}
}

void	draw_verticale(t_draw d, t_data *c)
{
	d.z1 = (c->final_tab[d.y + 1][d.x]) * (d.scale_z);
	d.x1 = ((d.x)) * (scale_x(&d, c));
	d.y1 = (((d.y + 1) * scale_y(&d, c) - c->final_tab[d.y + 1][d.x]));
	draw_isometrique(&d.x1, &d.y1, d.z1);
	bresenham(&d);
}

void	draw_horizontale(t_draw d, t_data *c)
{
	d.z1 = (c->final_tab[d.y][d.x + 1]) * (d.scale_z);
	d.x1 = ((d.x +1)) * scale_x(&d, c);
	d.y1 = (((d.y) * scale_y(&d, c) - c->final_tab[d.y][d.x + 1]));
	draw_isometrique(&d.x1, &d.y1, d.z1);
	bresenham(&d);
}

void	draw_isometrique(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (LARGEUR / 2.5) + (tmp_x - tmp_y) * cos(ANGLE) / 2.81;
	*y = (HAUTEUR / 2.81) + (((tmp_x + tmp_y) * sin(ANGLE)) - z) / 3;
}
