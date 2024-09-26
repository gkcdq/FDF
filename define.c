/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:20:56 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/26 02:27:57 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_cor(t_data *cor)
{
	cor->x_max = 0;
	cor->y_max = 0;
	cor->x = 0;
	cor->y = 0;
	cor->final_tab = NULL;
}

void	define_draw(t_draw *drw)
{
	drw->x0 = 0;
	drw->y0 = 0;
	drw->x1 = 0;
	drw->y1 = 0;
}

void	define_points_start(t_draw *drw, t_data *cor)
{
	drw->z0 = cor->final_tab[drw->y][drw->x] * drw->scale_z;
	drw->x0 = (drw->x * scale_x(drw, cor));
	drw->y0 = (drw->y * scale_y(drw, cor) - cor->final_tab[drw->y][drw->x]);
}

void	free_all(t_data *cor)
{
	int	y;

	y = 0;
	while (y < cor->y_max)
	{
		free(cor->final_tab[y]);
		y++;
	}
	free(cor->final_tab);
}
