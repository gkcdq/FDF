#include "fdf.h"

void    draw_lines(t_matrice *cor, t_mlx *mlx)
{
        int x, y;
        int x0, y0;
        int x1, y1;
        for (y = 0; y < cor->y_max; y++)
        {
                for (x = 0; x < cor->x_max; x++)
                {
                        x0 = x * 10;
                        y0 = y * 10 - cor->matrice[y][x];
                        if (x + 1 < cor->x_max)
                        {
                                x1 = (x + 1) * 10;
                                y1 = y * 10 - cor->matrice[y][x + 1];
                                bresenham(x0, y0, x1, y1, mlx);
                        }
                        if (y + 1 < cor->y_max)
                        {
                                x1 = x * 10;
                                y1 = (y + 1) * 10 - cor->matrice[y + 1][x];
                                bresenham(x0, y0, x1, y1, mlx);
                        }
                }
        }
}