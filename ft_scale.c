#include "fdf.h"

double   ft_scale(t_matrice *cor)
{
    double scale_z;

    scale_z = (double)HAUTEUR_MAX / (cor->y_max * 10);
    return (scale_z);
}
