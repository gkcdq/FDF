/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:49 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/16 15:35:12 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_scale(coord *cor)
{
	double	diffz;

	diffz = (double)HAUTEUR / (cor->ymax + cor->x_max);
	return (diffz);
}

double	scale_x(t_draw *drw)
{
	drw->scale_x = (double)SCL_LARGEUR / 40;
	return (drw->scale_x);
}

double	scale_y(t_draw *drw)
{
	drw->scale_y = (double)SCL_HAUTEUR / 40;
	return (drw->scale_y);
}