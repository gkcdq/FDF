#include "fdf.h"

void bresenham(t_draw *drw, t_mlx *mlx)
{
    t_brs *brs;

    brs = malloc(sizeof(t_brs));
    if (!brs)
        return ;
    little_bresenham(brs, drw);
    while (1)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, drw->x0, drw->y0, 0xFFFFFF);
        if (drw->x0 == drw->x1 && drw->y0 == drw->y1)
            break;
        brs->e2 = 2 * brs->error;
        if (brs->e2 > -brs->dy)
        {
            brs->error -= brs->dy;
            drw->x0 += brs->sx;
        }
        if (brs->e2 < brs->dx)
        {
            brs->error += brs->dx;
            drw->y0 += brs->sy;
        }
    }
    free(brs);
}

void    little_bresenham(t_brs *brs, t_draw *drw)
{
    brs->dx = abs(drw->x1 - drw->x0); // Largeur de la ligne a tracer en terme de pixel.
    brs->dy = abs(drw->y1 - drw->y0); // Hauteur de la ligne a tracer en terme de pixel.
    if (drw->x0 < drw->x1)
        brs->sx = 1; // Direction d'incrémentation de x, +1 pour aller vers la droite.
    else
        brs->sx = -1; // Direction d'incrémentation de x, -1 pour aller vers la gauche.
    if (drw->y0 < drw->y1)
        brs->sy = 1; // Direction d'incrémentation de y, +1 pour aller vers le bas.
    else
        brs->sy = -1; // Direction d'incrémentation de y, -1 pour aller vers le haut.
    brs->error = brs->dx - brs->dy;
}

