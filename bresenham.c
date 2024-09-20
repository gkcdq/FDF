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

void	bresenham(t_draw *drw)
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
}


