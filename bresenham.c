#include "fdf.h"

void bresenham(t_draw *drw)
{
    drw->brs = malloc(sizeof(t_brs));
    if (!drw->brs)
        return ;
    little_bresenham(drw->brs, drw);
    while (1)
    {
        mlx_pixel_put(drw->mlx->mlx, drw->mlx->win, drw->x0, drw->y0, 0xFFFFFF);
        if (drw->x0 == drw->x1 && drw->y0 == drw->y1)
            break;
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

void    little_bresenham(t_brs *brs, t_draw *drw)
{
    brs->dx = abs(drw->x1 - drw->x0); // Largeur de la ligne a tracer en terme de pixel.
    brs->dy = abs(drw->y1 - drw->y0); // Hauteur de la ligne a tracer en terme de pixel.
    if (drw->x0 < drw->x1)
        brs->sx = 1; // +1 pour aller vers la droite.
    else
        brs->sx = -1; // -1 pour aller vers la gauche.
    if (drw->y0 < drw->y1)
        brs->sy = 1; // +1 pour aller vers le bas.
    else
        brs->sy = -1; // -1 pour aller vers le haut.
    brs->error = brs->dx - brs->dy;
}
