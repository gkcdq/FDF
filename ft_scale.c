/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:49 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/16 15:41:53 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_scale(t_data *cor)
{
	double	diffz;

	diffz = (double)HAUTEUR / (cor->y_max * 3);
	return (diffz);
}

double	scale_x(t_draw *drw)
{
	drw->scale_x = (double)IMG_LARGEUR_MAX / 40;
	return (drw->scale_x);
}

double	scale_y(t_draw *drw)
{
	drw->scale_y = (double)IMG_HAUTEUR_MAX / 40;
	return (drw->scale_y);
}