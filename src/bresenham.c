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

void	bresenham(t_draw *dr)
{
	dr->color = 0xFFFFFF;
	dr->bre = malloc(sizeof(t_brs));
	if (!dr->bre)
		return ;
	little_bresenham(dr->bre, dr);
	while (1)
	{
		draw_pixel(dr->mlx, dr->x0, dr->y0, dr->color);
		if (dr->x0 == dr->x1 && dr->y0 == dr->y1)
			break ;
		dr->bre->e2 = 2 * dr->bre->error;
		if (dr->bre->e2 > -dr->bre->dy)
		{
			dr->bre->error -= dr->bre->dy;
			dr->x0 += dr->bre->sx;
		}
		if (dr->bre->e2 < dr->bre->dx)
		{
			dr->bre->error += dr->bre->dx;
			dr->y0 += dr->bre->sy;
		}
	}
	free(dr->bre);
}

void	little_bresenham(t_brs *bre, t_draw *dr)
{
	bre->dx = abs(dr->x1 - dr->x0);
	bre->dy = abs(dr->y1 - dr->y0);
	if (dr->x0 < dr->x1)
		bre->sx = 1;
	else
		bre->sx = -1;
	if (dr->y0 < dr->y1)
		bre->sy = 1;
	else
		bre->sy = -1;
	bre->error = bre->dx - bre->dy;
}