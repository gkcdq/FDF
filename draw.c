/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:26 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/20 16:24:52 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_draw *drw, t_data *cor)
{
	draw_calcul(drw, cor);
	ft_putendl_fd("Dessin complet!", 1);
}

void	draw_calcul(t_draw *drw, t_data *cor)
{
	drw->scale_z = ft_scale(cor);
	drw->y = -1;
	while (++drw->y < cor->y_max)
	{
		drw->x = -1;
		while (++drw->x < cor->x_max)
		{
			define_points_start(drw, cor);
			draw_isometrique(&drw->x0, &drw->y0, drw->z0);
			if (drw->x + 1 < cor->x_max)
				draw_horizontale(drw, cor);
			if (drw->y + 1 < cor->y_max)
				draw_verticale(drw, cor);
		}
	}
}

void	draw_verticale(t_draw *drw, t_data *cor)
{
	drw->z1 = cor->final_tab[drw->y + 1][drw->x] * drw->scale_z;
	drw->x1 = ((drw->x)) * (scale_x(drw, cor));
	drw->y1 = (((drw->y + 1) * scale_y(drw, cor) - cor->final_tab[drw->y + 1][drw->x]));
	draw_isometrique(&drw->x1, &drw->y1, drw->z1);
	//ft_printf("Dessin de la ligne vertical de (%d, %d) to (%d, %d)\n", drw->x0, drw->y0, drw->x1, drw->y1);
	bresenham(drw);
}

void	draw_horizontale(t_draw *drw, t_data *cor)
{
	drw->z1 = cor->final_tab[drw->y][drw->x + 1] * drw->scale_z;
	drw->x1 = ((drw->x + 1)) * scale_x(drw, cor);
	drw->y1 = (((drw->y) * scale_y(drw, cor) - cor->final_tab[drw->y][drw->x + 1]));
	draw_isometrique(&drw->x1, &drw->y1, drw->z1);
	//ft_printf("Dessin de la ligne horizontal de (%d, %d) to (%d, %d)\n", drw->x0, drw->y0, drw->x1, drw->y1);
	bresenham(drw);
}

void	draw_isometrique(int *x, int *y, int z)
{
	return ;
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(ANGLE);
	*y = (((tmp_x + tmp_y) * sin(ANGLE)) - z);
}

