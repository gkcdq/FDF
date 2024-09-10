#include "fdf.h"

void	draw_lines(t_draw *drw, t_matrice *cor)
{
	draw_calcul(drw, cor);
	ft_putendl_fd("Dessin complet.", 1);
}
// Creer une fonction qui calcul et trace tute les lignes de la matrice.
void	draw_calcul(t_draw *drw, t_matrice *cor)
{
	drw->y = 0;
	while (drw->y < cor->y_max)
	{
		drw->x = 0;
		while (drw->x < cor->x_max)
		{
			drw->z0 = cor->matrice[drw->y][drw->x];
			drw->x0 = drw->x * 10;
			drw->y0 = drw->y * 10 - cor->matrice[drw->y][drw->x];
			draw_isometric(&drw->x0, &drw->y0, drw->z0);
			ft_printf("Dessin point (%d, %d)\n", drw->x0, drw->y0);
            		if (drw->x + 1 < cor->x_max)
				draw_horizontale(drw, cor);
            		if (drw->y + 1 < cor->y_max)
				draw_verticale(drw, cor);
			drw->x++;
		}
		drw->y++;
	}
}
// Tracer les lignes horzontale de la matrice.
void	draw_horizontale(t_draw *drw, t_matrice *cor)
{
	drw->z1 = cor->matrice[drw->y][drw->x + 1];
	drw->x1 = (drw->x + 1) * 10;
	drw->y1 = drw->y * 10 - cor->matrice[drw->y][drw->x + 1];
	draw_isometric(&drw->x1, &drw->y1, drw->z1);
	ft_printf("Dessin de la ligne horizontal de (%d, %d) to (%d, %d)\n", drw->x0, drw->y0, drw->x1, drw->y1);
	bresenham(drw);
}
// Tracer les lignes verticales de la matrice.
void	draw_verticale(t_draw *drw, t_matrice *cor)
{
	drw->z1 = cor->matrice[drw->y + 1][drw->x];
	drw->x1 = drw->x * 10;
	drw->y1 = (drw->y + 1) * 10 - cor->matrice[drw->y + 1][drw->x];
	draw_isometric(&drw->x1, &drw->y1, drw->z1);
	ft_printf("Dessin de la ligne vertical de (%d, %d) to (%d, %d)\n", drw->x0, drw->y0, drw->x1, drw->y1);
	bresenham(drw);
}
void	draw_isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ANGLE_ISO);
	*y = (previous_x + previous_y) * sin(ANGLE_ISO) - z;
	ft_printf("Transformation Isometric: (%d, %d, %d) -> (%d, %d)\n", previous_x, previous_y, z, *x, *y);
}
