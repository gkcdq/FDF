#include "fdf.h"

void center_image(t_mlx *mlx)
{
    int x;
    int y;

    x = (mlx->largeur_max - mlx->img_largeur_max) / 2;
    y = (mlx->hauteur_max - mlx->img_hauteur_max) / 2;
    mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, x, y);
}

