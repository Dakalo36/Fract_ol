
#include "frac.h"
int         get_color(unsigned int n, unsigned int max_iter)
{
    unsigned int n_r;
    unsigned int n_r3;
    double       t;
    int          r;
    int          g;
    int          b;
    int          nn;

    n_r = 256;
    n_r3 = n_r * n_r * n_r;
    t = (double)n / (double)max_iter;
    n = (int)(t * (double)n_r3);
    b = n / (n_r * n_r);
    nn = n - b * n_r * n_r;
    r = nn / n_r;
    g = nn - r * n_r;
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));  
}
void        ft_init_mand(t_mandelbrot *mand)
{
    mand->minRe = -2.0;
    mand->maxRe = 1.0;
    mand->minIm = -1.2;
    mand->maxIm = mand->minIm + (mand->maxRe - mand->minRe) * W_HEIGHT / W_WIDTH;
    mand->re_factor = (mand->maxRe - mand->minRe) / (W_WIDTH - 1);
    mand->im_factor = (mand->maxIm - mand->minIm) / (W_HEIGHT - 1);    
}
void        mandelbrot(t_env *e)
{
    t_mandelbrot    mand;
    unsigned int    max_iter;
    //int             is_inside;
    unsigned int    y;
    unsigned int    x;
    unsigned int    n;

    max_iter = 50;
   // is_inside = 1;
    y = 0;
    ft_init_mand(&mand);
    while (y < W_HEIGHT)
    {
        mand.c_im = mand.maxIm - y * mand.im_factor;
        x = 0;
        while (x < W_WIDTH)
        {
            mand.c_re = mand.minRe + x * mand.re_factor;
            mand.z_re = mand.c_re;
            mand.z_im = mand.c_im;
            //is_inside = 1;
            n = 0;
            while (n < max_iter)
            {
                mand.z_re2 = mand.z_re * mand.z_re;
                mand.z_im2 = mand.z_im * mand.z_im;
                if (mand.z_re2 + mand.z_im2 > 4)
                {
                    //is_inside = 0;
                    break;
                }
                mand.z_im = 2 * mand.z_re * mand.z_im + mand.c_im;
                mand.z_re = mand.z_re2 - mand.z_im2 + mand.c_re;
                n++;
            }
            //if (is_inside == 1)
                mlx_pixel_put(e->mlx, e->win, x, y, get_color(n, max_iter));
            x++;
        }
        y++;
    }
    mlx_loop(e->mlx);
}
