/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drwaw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharraqi <nharraqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:10:26 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/14 20:50:36 by nharraqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_draw *drw, coord *cor)
{
	draw_calcul(drw, cor);
	ft_putendl_fd("Dessin completement complet!", 1);
}

void	draw_calcul(t_draw *drw, coord *cor)
{
	drw->scale_z = scale(cor);
	drw->y = 0;
	drw->offset_x = (int)LARGEUR / 2;
	drw->offset_y = (int)HAUTEUR / 2;
	while (drw->y < cor->ymax)
	{
		drw->x = 0;
		while (drw->x < cor->xmax)
		{
			drw->z0 = cor->final_tab[drw->y][drw->x] * drw->scale_z;
			drw->x0 = drw->x * scale_x(drw) + drw->offset_x;
			drw->y0 = drw->y * scale_y(drw) - cor->final_tab[drw->y][drw->x]
				+ drw->offset_y;
			draw_isometrique(&drw->x0, &drw->y0, drw->z0);
			if (drw->x + 1 < cor->xmax)
				draw_horizontale(drw, cor);
			if (drw->y + 1 < cor->ymax)
				draw_verticale(drw, cor);
			drw->x++;
		}
		drw->y++;
	}
}

void	draw_verticale(t_draw *drw, coord *cor)
{
	drw->offset_x = (LARGEUR - (cor->xmax * 20)) / 2;
	drw->offset_y = (HAUTEUR - (cor->ymax * 20)) / 2;
	drw->scale_z = scale(cor);
	drw->z1 = cor->final_tab[drw->y + 1][drw->x] * drw->scale_z;
	drw->x1 = drw->x * scale_x(drw) + drw->offset_x;
	drw->y1 = ((drw->y + 1) * scale_y(drw) - cor->final_tab[drw->y + 1][drw->x]) + drw->offset_y;
	draw_isometrique(&drw->x1, &drw->y1, drw->z1);
	bresenham(drw);
}

void	draw_horizontale(t_draw *drw, coord *cor)
{
	drw->offset_x = (LARGEUR - (cor->xmax * 20)) / 2;
	drw->offset_y = (HAUTEUR - (cor->ymax * 20)) / 2;
	drw->scale_z = scale(cor);
	drw->z1 = cor->final_tab[drw->y][drw->x + 1] * drw->scale_z;
	drw->x1 = (drw->x + 1) * scale_x(drw) + drw->offset_x;
	drw->y1 = (drw->y * scale_y(drw) - cor->final_tab[drw->y][drw->x + 1]) + drw->offset_y;
	draw_isometrique(&drw->x1, &drw->y1, drw->z1);
	bresenham(drw);
}

void	draw_isometrique(int *x, int *y, int z)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(ANGLE);
	*y = (((tmp_x + tmp_y) * sin(ANGLE)) - z);
}

