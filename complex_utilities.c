#include "fractol.h"

t_complex	com_add(t_complex a, t_complex b)
{
    t_complex z;

    z.r = a.r + b.r;
    z.i = a.i + b.i;
    return (z);
}

t_complex	com_mul(t_complex a, t_complex b)
{
    t_complex z;

    z.r = a.r * b.r - a.i * b.i;
    z.i = a.r * b.i + a.i * b.r;
    return (z);
}

t_complex	com_div(t_complex a, t_complex b)
{
    t_complex z;

    z.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
    z.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);
    return (z);
}
