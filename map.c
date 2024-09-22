/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:21:06 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/22 16:20:05 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_mesure(t_data *cor, char *file)
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
	while (tab[cor->x_max])
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
	close(fd);
}

void	check_matrice(t_data *cor, char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
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
		if (i < cor->x_max || i > cor->x_max)
			ft_putendl_fd("pas le meme nombre d'element par ligne! (check_matrice)", 1);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	copi_matrice(t_data *cor, char *file)
{
	int fd;
	char *line;
	char **line_tab;

	fd = open(file, O_RDONLY);
	cor->final_tab = malloc(cor->y_max * sizeof(int *));
	while (cor->y < cor->y_max)
	{
		cor->final_tab[cor->y] = malloc(cor->x_max * sizeof(int));
		line = get_next_line(fd);
		line_tab = ft_split(line, ' ');
		free(line);
		cor->x = 0;
		while (cor->x < cor->x_max)
		{
			cor->final_tab[cor->y][cor->x] = ft_atoi(line_tab[cor->x]);
			free(line_tab[cor->x]);
			cor->x++;
		}
		cor->y++;
		free(line_tab);
	}
}