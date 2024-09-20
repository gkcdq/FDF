/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:16:49 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/20 23:16:22 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_scale(t_data *cor)
{
	double	H;

	H = ((double)HAUTEUR / (cor->y_max + cor->x_max));
	return (H);
}

double	scale_x(t_draw *drw, t_data *cor)
{
	drw->scale_x = ((double)LARGEUR / cor->x_max);
	return (drw->scale_x);
}

double	scale_y(t_draw *drw, t_data *cor)
{
	drw->scale_y = ((double)HAUTEUR / cor->y_max);
	return (drw->scale_y);
}