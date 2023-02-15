#include "fractol.h"

t_complex com_mul(t_complex a, t_complex b)
{
    t_complex z;
    z.r = a.r * b.r - a.i * b.i;
    z.i = a.r * b.i + a.i * b.r;
    return z;
}
