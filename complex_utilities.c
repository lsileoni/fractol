#include "fractol.h"

t_complex	com_mul(t_complex a, t_complex b)
{
    t_complex z;

    z.r = a.r * b.r - a.i * b.i;
    z.i = a.r * b.i + a.i * b.r;
    return (z);
}

t_complex	com_div(t_complex x,t_complex y)
{
    t_complex z;

    z.r = (x.r*y.r + x.i*y.i)/(y.r*y.r+y.i*y.i);
    z.i = (x.i*y.r - x.r*y.i)/(y.r*y.r + y.i*y.i);
    return (z);
}
