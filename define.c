#include "fdf.h"

void define_coordonnees(t_matrice *cor)
{
    cor->x_max = 0;
    cor->y_max = 0;
    cor->ligne = 0;
    cor->colonne = 0;
    cor->matrice = NULL;
}

void define_image(t_mlx *mlx)
{
    mlx->largeur_max = LARGEUR_MAX;
    mlx->hauteur_max = HAUTEUR_MAX;
    mlx->img_largeur_max = LARGEUR_MAX;
    mlx->img_hauteur_max = HAUTEUR_MAX;
}
