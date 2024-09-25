#include "fdf.h"

int		ft_close(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}

int	key_handler(int key, t_mlx *mlx)
{
	if (key == 65307 || key == 17)
		ft_close(mlx);
	return(0);
}
void	manage_close(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_handler, mlx);
	mlx_hook(mlx->win, 17, 65307, ft_close, mlx);
}