/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:01:46 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/25 22:00:10 by tmilin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	cor;
	t_mlx	mlx;
	t_draw	drw;

	if (ac != 2)
	{
		ft_putendl_fd("Usage: ./fdf map_file", 2);
		return (1);
	}
	define_cor(&cor);
	define_draw(&drw);
	map_mesure(&cor, av[1]);
	check_matrice(&cor, av[1]);
	copi_matrice(&cor, av[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, LARGEUR, HAUTEUR, "FDF");
	mlx.img = mlx_new_image(mlx.mlx, (LARGEUR), (HAUTEUR));
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits, &mlx.size, &mlx.end);
	drw.mlx = &mlx;
	drw.cor = &cor;
	draw_lines(&drw, &cor);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, (0), (0));
	manage_close(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}	
