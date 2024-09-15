/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharraqi <nharraqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:49 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/14 19:40:48 by nharraqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_scale(coord *cor)
{
	double	diffz;

	diffz = (double)HAUTEUR / (cor->ymax + cor->xmax);
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