/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilin <tmilin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:01:46 by nharraqi          #+#    #+#             */
/*   Updated: 2024/09/22 17:30:17 by tmilin           ###   ########.fr       */
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
	define_cor(&cor);
	define_draw(&drw);
	map_mesure(&cor, av[1]);
	check_matrice(&cor, av[1]);
	copi_matrice(&cor, av[1]);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, LARGEUR, HAUTEUR, "FDF");
	mlx.img = mlx_new_image(mlx.mlx, (LARGEUR), (HAUTEUR));
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.size_line, &mlx.endian);
	drw.mlx = &mlx;
	drw.cor = &cor;
	draw_lines(&drw, &cor);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, (0), (0));
	h_management(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
int		ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	key_handler(int key, t_mlx *mlx)
{
	if (key == 65307)
		ft_close(mlx);
	return(0);
}
void	h_management(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx_hook(mlx->win, 0, 65307, ft_close, mlx);
}
	