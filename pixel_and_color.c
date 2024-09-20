#include "fdf.h"

void	draw_pixel(t_mlx *mlx, int x, int y, int z)
{
	char *pxl;
    unsigned int color;

	if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
	{
		pxl = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
		color = color_pxl(z);
		*(unsigned int *)pxl = color;
	}
}

unsigned int color_pxl(int z)
{
    unsigned int color_value;

    if (z < -40 && z >= -100)
        color_value = BLANC;
    else if (z >= 0 && z <= 10)
        color_value = ROUGE;
    else if (z > 10 && z <= 30)
        color_value = VERT;
    else if (z > 30 && z <= 80)
        color_value = VERT_ORANGE;
    else if (z > 70 && z <= 120)
        color_value = ORANGE;
    else if (z >120 && z <= 160)
        color_value = ROUGE_ORANGE;
    else if (z > 160 && z <= 200)
        color_value = ROUGE;
    else if (z > 200 && z <= 240)
        color_value = BLEU;
    else
        color_value = BLANC;

    return (color_value);
}