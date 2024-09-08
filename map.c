/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:39:08 by tmilin            #+#    #+#             */
/*   Updated: 2024/09/08 15:36:40 by tmilin           ###   ########.fr       */
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
