/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:39:08 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/07 19:32:49 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Lecture des coordonnées (calculer la largeur et la hauteur de notre matrice.)
void	map_coord(t_matrice *cor, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_printf("Erreur lors de l'ouverture du fichier (map_coord).");
	line = get_next_line(fd);
	if (!line)
		ft_printf("Le fichier est vide ou n'a pas pu etre lu (map_coord).");
	tab = ft_split(line, ' ');
	while (tab[cor->x_max] != NULL)
	{
		free(tab[cor->x_max]);
		cor->x_max++;
	}
	while (line)
	{
		free(line);
		cor->y_max++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
}

// check s'il y a un cas d'erreur avec la map.
void	check_map(t_matrice *cor, char *file)
{
	int		fd;
	char	*line;
	char	**tab;
	int		new_x;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		new_x = 0;
		free(line);
		while (tab[new_x] != NULL)
		{
			free(tab[new_x]);
			new_x++;
		}
		free(tab);
		if (new_x != cor->x_max)
			ft_printf("Erreur lors du check de la map (check map).");
		line = get_next_line(fd);
	}
	close(fd);
	return ;
}
// faire une fonction qui copie la matrix et la tranforme en un tableau de int;
// tant que y (ma hauteur) est different de y_max (hauteur total) je boucle;
// j'alloue la memoire pour x (int * le nombre de colonne);

int	copi_matrice(t_matrice *cor, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	cor->matrice = malloc(sizeof(int *) * cor->y_max);
	if (!cor->matrice)
		return (1);
	while (cor->ligne < cor->y_max)
	{
		line = get_next_line(fd);
		tab = ft_split(line, ' ');
		cor->matrice[cor->ligne] = malloc(cor->x_max * sizeof(int));
		cor->colonne = 0;
		while (cor->colonne < cor->x_max)
		{
			cor->matrice[cor->ligne][cor->colonne] = ft_atoi(tab[cor->colonne]);
			free(tab[cor->colonne]);
			cor->colonne++;
		}
		free(tab);
		free(line);
		cor->ligne++;
	}
	close(fd);
	return (0);
}

void	bresenham(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		// Placer un pixel à la position actuelle
		mlx_pixel_put(mlx->mlx, mlx->win, x0, y0, 0xFFFFFF);
		// Si on atteint le point final, sortir de la boucle
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		// Ajustement de la direction selon l'erreur
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_lines(t_matrice *cor, t_mlx *mlx)
{
	int x, y;
	int x0, y0;
	int x1, y1;
	for (y = 0; y < cor->y_max; y++)
	{
		for (x = 0; x < cor->x_max; x++)
		{
			// Obtenir les coordonnées (x0, y0) et z0
			x0 = x * 10;                      // Échelle pour espacer les points
			y0 = y * 10 - cor->matrice[y][x]; // Ajuster avec z (hauteur)
			// Si on peut dessiner une ligne vers la droite (x+1, y)
			if (x + 1 < cor->x_max)
			{
				x1 = (x + 1) * 10;
				y1 = y * 10 - cor->matrice[y][x + 1];
				// Tracer la ligne horizontale avec Bresenham
				bresenham(x0, y0, x1, y1, mlx);
			}
			// Si on peut dessiner une ligne vers le bas (x, y+1)
			if (y + 1 < cor->y_max)
			{
				x1 = x * 10;
				y1 = (y + 1) * 10 - cor->matrice[y + 1][x];
				// Tracer la ligne verticale avec Bresenham
				bresenham(x0, y0, x1, y1, mlx);
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_matrice	cor;
	t_mlx		mlx;

	if (ac == 2)
	{
		// Initialiser la structure cor et charger les données de la matrice
		cor.x_max = 0;
		cor.y_max = 0;
		cor.ligne = 0;
		cor.colonne = 0;
		cor.matrice = NULL;
		map_coord(&cor, av[1]);
		check_map(&cor, av[1]);
		copi_matrice(&cor, av[1]);
		// Initialiser MiniLibX et la fenêtre
		mlx.mlx = mlx_init();
		mlx.largeur_max = 1200;
		mlx.hauteur_max = 600;
		mlx.img_largeur_max = 1100;
		mlx.img_hauteur_max = 500;
		mlx.img = mlx_new_image(mlx.mlx, mlx.img_largeur_max,	mlx.img_hauteur_max);
		mlx.win = mlx_new_window(mlx.mlx, mlx.largeur_max, mlx.hauteur_max,
				"FDF");
		// Dessiner les lignes de la matrice avec Bresenham
		draw_lines(&cor, &mlx);
		// Boucle d'événements MiniLibX
		mlx_loop(mlx.mlx);
	}
	return (0);
}
