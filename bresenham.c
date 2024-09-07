#include "fdf.h"

void bresenham(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
    t_brs *brs;

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

void    little_bresenham(t_brs *brs)
{
    brs = malloc(sizeof(t_brs));
    if (!brs)
        return ;
    brs->dx = abs(x1 - x0); // largeur de la ligne a tracer en terme de pixel.
    brs->dy = abs(y1 - y0); // hauteur de la ligne a tracer en terme de pixel.
    if (x0 < x1)
        brs->sx = 1;
        else
            brs->sx = -1
    if (y0 < y1)
        brs->sy
    brs->sy = (y0 < y1) ? 1 : -1;
    brs->error = brs->dx - brs->dy;
}