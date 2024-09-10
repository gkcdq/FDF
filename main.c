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
    define_coordonnees(&cor);
    map_coord(&cor, av[1]);
    check_map(&cor, av[1]);
    copi_matrice(&cor, av[1]);
    mlx.mlx = mlx_init();
    define_image(&mlx);
    mlx.img = mlx_new_image(mlx.mlx, mlx.img_largeur_max, mlx.img_hauteur_max);
    mlx.win = mlx_new_window(mlx.mlx, mlx.largeur_max, mlx.hauteur_max, "FDF");
    // Initialiser la structure de dessin
    drw.mlx = &mlx;
    // Dessiner les lignes de la matrice avec Bresenham en vue isométrique
    draw_lines(&drw, &cor);
    mlx_loop(mlx.mlx);
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


