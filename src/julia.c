
#include "frac.h"

void        ft_julia_init(t_julia *julia)
{
    julia->zoom = 1;
    julia->moveX = 0;
    julia->moveY = 0;
    julia->cRe = -0.6;
    julia->cIm = 0.470150;
}
void        julia(t_env *e)
{
    t_julia         julia;
    unsigned int    max_iter;
    unsigned int    y;
    unsigned int    x;
    unsigned int    n;

    max_iter = 500;
    y = 0;
    ft_julia_init(&julia);
    while (y < W_HEIGHT)
    {
        x = 0;
        while (x < W_WIDTH)
        {
            //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
            julia.newRe = 1.5 * (x - W_WIDTH / 2) / (0.5 * julia.zoom * W_WIDTH);
            julia.newIm = (y - W_HEIGHT / 2) / (0.5 * julia.zoom * W_HEIGHT);
            n = 0;
            while ((julia.newRe * julia.newRe + julia.newIm * julia.newIm) < 4 && n < max_iter)
            {
                julia.oldRe = julia.newRe;
                julia.oldIm = julia.newIm;
                //the actual iteration, the real and imaginary part are calculated
                julia.newRe = julia.oldRe * julia.oldRe - julia.oldIm * julia.oldIm + julia.cRe;
                julia.newIm = 2 * julia.oldRe * julia.oldIm + julia.cIm;
                //if the point is outside the circle with radius 2: stop
                n++;
            }
            if (n < max_iter)
                mlx_pixel_put(e->mlx, e->win, x, y, get_color(n, max_iter));
            x++;
        }
        y++;
    }
    mlx_loop(e->mlx);
}