
#ifndef FRAC_H
# define FRAC_H

#include <mlx.h>
#include "../libft/ft_printf.h"

# define W_WIDTH 400
# define W_HEIGHT 400

typedef struct  s_env 
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *data;
    int         bpp;
    int         s_line;
    int         ind;
    void        (*fractol)();

}               t_env;

typedef struct			s_mandelbrot
{
	long double			minRe;
	long double			maxRe;
	long double			minIm;
	long double			maxIm;
	long double			re_factor;
	long double			im_factor;
	long double			c_re;
	long double			c_im;
	long double			z_re;
	long double			z_re2;
	long double			z_im;
	long double			z_im2;
}						t_mandelbrot;

void        mandelbrot(t_env *e);
#endif