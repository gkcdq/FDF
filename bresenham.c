#include "fdf.h"

void bresenham(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
    t_brs *brs;

    brs = malloc(sizeof(t_brs));
    if (!brs)
        return ;
    little_bresenham(brs, x0, y0, x1, y1);
    while (1)
    {
        mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, 0xFFFFFF);
        if (x0 == x1 && y0 == y1)
            break;
        brs->e2 = 2 * brs->error;
        if (brs->e2 > -brs->dy)
        {
            brs->error -= brs->dy;
            x0 += brs->sx;
        }
        if (brs->e2 < brs->dx)
        {
            brs->error += brs->dx;
            y0 += brs->sy;
        }
    }
    free(brs);
}

void    little_bresenham(t_brs *brs, int x0, int y0, int x1, int y1)
{
    brs->dx = abs(x1 - x0); // Largeur de la ligne a tracer en terme de pixel.
    brs->dy = abs(y1 - y0); // Hauteur de la ligne a tracer en terme de pixel.
    if (x0 < x1)
        brs->sx = 1; // Direction d'incrémentation de x, +1 pour aller vers la droite.
    else
        brs->sx = -1; // Direction d'incrémentation de x, -1 pour aller vers la gauche.
    if (y0 < y1)
        brs->sy = 1; // Direction d'incrémentation de y, +1 pour aller vers le bas.
    else
        brs->sy = -1; // Direction d'incrémentation de y, -1 pour aller vers le haut.
    brs->error = brs->dx - brs->dy;
}