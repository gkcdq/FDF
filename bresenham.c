/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharraqi <nharraqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:22:19 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:47 by nharraqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	bresenham(t_draw *drw)
{
	drw->brs = malloc(sizeof(t_brs));
	if (!drw->brs)
		return ;
	little_bresenham(drw->brs, drw);
	while (1)
	{
		draw_pixel(drw->mlx, drw->x0, drw->y0, drw->z0);
		if (drw->x0 == drw->x1 && drw->y0 == drw->y1)
			break ;
		drw->brs->e2 = 2 * drw->brs->error;
		if (drw->brs->e2 > -drw->brs->dy)
		{
			drw->brs->error -= drw->brs->dy;
			drw->x0 += drw->brs->sx;
		}
		if (drw->brs->e2 < drw->brs->dx)
		{
			drw->brs->error += drw->brs->dx;
			drw->y0 += drw->brs->sy;
		}
	}
	free(drw->brs);
}

void	little_bresenham(t_brs *brs, t_draw *drw)
{
	brs->dx = abs(drw->x1 - drw->x0);
	brs->dy = abs(drw->y1 - drw->y0);
	if (drw->x0 < drw->x1)
		brs->sx = 1;
	else
		brs->sx = -1;
	if (drw->y0 < drw->y1)
		brs->sy = 1;
	else
		brs->sy = -1;
	brs->error = brs->dx - brs->dy;
}*/

void	non_diagonal_line(t_draw *drw)
{
	int dx = abs(drw->x1 - drw->x0);
	int dy = abs(drw->y1 - drw->y0);
	int sx = (drw->x0 < drw->x1) ? 1 : -1;
	int sy = (drw->y0 < drw->y1) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		// Dessiner le pixel
		draw_pixel(drw->mlx, drw->x0, drw->y0, drw->z0);
		
		// Si on a atteint le point final
		if (drw->x0 == drw->x1 && drw->y0 == drw->y1)
			break;

		int e2 = err * 2;

		// Ajuster le mouvement en fonction de l'erreur
		if (e2 > -dy) // Se déplacer horizontalement si possible
		{
			err -= dy;
			drw->x0 += sx;
		}
		else if (e2 < dx) // Se déplacer verticalement si possible
		{
			err += dx;
			drw->y0 += sy;
		}
	}
}

