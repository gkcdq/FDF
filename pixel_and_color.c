#include "fdf.h"

void	draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	char *pxl;
	// Vérifier que les coordonnées sont dans les limites de l'image
	if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
	{
		// Calculer l'adresse du pixel dans l'image
		pxl = mlx->addr + (y * mlx->size_line + x * (mlx->bits_per_pixel / 8));
		// Écrire la couleur dans l'adresse du pixel
		*(unsigned int *)pxl = color;
	}
}

/*unsigned int color_pxl(t_draw *drw)
{
    if (drw->z <= -100)
        drw->color_value = BLANC;
    else if (drw->z <= -40)
        drw->color_value = GRIS;
    else if (drw->z <= 10)
        drw->color_value = ROUGE;
    else if (drw->z <= 40)
        drw->color_value = ROUGE_ORANGE;
    else if (drw->z <= 80)
        drw->color_value = ORANGE;
    else if (drw->z <= 120)
        drw->color_value = JAUNE_ORANGE;
    else if (drw->z <= 160)
        drw->color_value = JAUNE;
    else if (drw->z <= 200)
        drw->color_value = VERT_JAUNE;
    else if (drw->z <= 240)
        drw->color_value = VERT;
    else
        drw->color_value = BLANC;

    return (drw->color_value);
}*/