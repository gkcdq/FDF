#include "fdf.h"

#include "fdf.h"

int main(int ac, char **av)
{
    t_matrice cor;
    t_mlx mlx;
    t_draw drw;

    if (ac != 2)
    {
        ft_putendl_fd("Usage: ./fdf map_file", 2);
        return (1);
    }

    // Initialiser la structure cor et charger les données de la matrice
    cor.x_max = 0;
    cor.y_max = 0;
    cor.ligne = 0;
    cor.colonne = 0;
    cor.matrice = NULL;
    map_coord(&cor, av[1]);
    check_map(&cor, av[1]);
    if (copi_matrice(&cor, av[1]) == -1)
    {
        ft_putendl_fd("Error: Failed to copy matrix", 2);
        return (1);
    }

    // Initialiser MiniLibX et la fenêtre
    mlx.mlx = mlx_init();
    if (!mlx.mlx)
    {
        ft_putendl_fd("Error: Failed to initialize MiniLibX", 2);
        return (1);
    }
    mlx.largeur_max = 1120;
    mlx.hauteur_max = 920;
    mlx.img_largeur_max = 1120;
    mlx.img_hauteur_max = 920;
    mlx.img = mlx_new_image(mlx.mlx, mlx.img_largeur_max, mlx.img_hauteur_max);
    if (!mlx.img)
    {
        ft_putendl_fd("Error: Failed to create image", 2);
        return (1);
    }
    mlx.win = mlx_new_window(mlx.mlx, mlx.largeur_max, mlx.hauteur_max, "FDF");
    if (!mlx.win)
    {
        ft_putendl_fd("Error: Failed to create window", 2);
        return (1);
    }

    // Initialiser la structure de dessin
    drw.mlx = &mlx;

    // Dessiner les lignes de la matrice avec Bresenham en vue isométrique
    centrer_l_image(&drw);
    draw_lines(&drw, &cor);

    // Boucle d'événements MiniLibX
    mlx_loop(mlx.mlx);

    // Libérer la mémoire et nettoyer
    int i;
    for (i = 0; i < cor.y_max; i++)
    {
        free(cor.matrice[i]);
    }
    free(cor.matrice);
    mlx_destroy_image(mlx.mlx, mlx.img);
    mlx_destroy_window(mlx.mlx, mlx.win);

    return (0);
}


