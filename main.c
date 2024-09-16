/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:01:46 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/16 15:40:09 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data cor;
	t_mlx mlx;
	t_draw drw;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf map_file", 2);
		return (1);
	}

	// Initialiser les structures
	define_cor(&cor);
	define_draw(&drw);
	map_mesure(&cor, av[1]);
	check_matrice(&cor, av[1]);
	copi_matrice(&cor, av[1]);

	// Initialisation de mlx
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, LARGEUR, HAUTEUR, "FDF");
	mlx.img = mlx_new_image(mlx.mlx, LARGEUR, HAUTEUR);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.size_line,
			&mlx.endian);
	// Initialiser la structure de dessin
	drw.mlx = &mlx;
	drw.cor = &cor;

	// Dessiner les lignes de la matrice avec Bresenham en vue isométrique
	draw_lines(&drw, &cor);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);

	// Libération de la mémoire
	int i;
	for (i = 0; i < cor.y_max; i++)
	{
		free(cor.final_tab[i]);
	}
	free(cor.final_tab);
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_destroy_window(mlx.mlx, mlx.win);

	return (0);
}