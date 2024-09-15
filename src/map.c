/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nharraqi <nharraqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:21:06 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/13 22:41:15 by nharraqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_mesure(coord *cor, char *file)
{
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putendl_fd("probleme fd (map_mesure)", 1);
	line = get_next_line(fd);
	if (!line)
		ft_putendl_fd("probleme line = gnl(map_mesure)", 1);
	tab = ft_split(line, ' ');
	while (tab[cor->xmax])
	{
		free(tab[cor->xmax]);
		cor->xmax++;
	}
	while (line)
	{
		free(line);
		cor->ymax++;
		line = get_next_line(fd);
	}
	free(line);
	free(tab);
	close(fd);
}

void	check_matrice(coord *cor, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putendl_fd("probleme fd (check_matrice)", 1);
	line = get_next_line(fd);
	if (!line)
		ft_putendl_fd("probleme line = gnl(check_matrice)", 1);
	while (line)
	{
		tab = ft_split(line, ' ');
		free(line);
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		if (i < cor->xmax || i > cor->xmax)
			ft_putendl_fd("pas le meme nombre d'element par ligne! (check_matrice)",
				1);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	copi_matrice(coord *cor, char *file)
{
	int fd;
	char *line;
	char **line_tab;

	fd = open(file, O_RDONLY);
	cor->final_tab = malloc(cor->ymax * sizeof(int *));
	while (cor->y < cor->ymax)
	{
		cor->final_tab[cor->y] = malloc(cor->xmax * sizeof(int));
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		free(line);
		cor->x = -1;
		while (++cor->x < cor->xmax)
		{
			cor->final_tab[cor->y][cor->x] = ft_atoi(line_tab[cor->x]);
			free(line_tab[cor->x]);
		}
		cor->y++;
		free(line_tab);
	}
}