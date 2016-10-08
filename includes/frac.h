
#ifndef FRAC_H
# define FRAC_H

#include <mlx.h>
#include "../libft/ft_printf.h"

# define W_WIDTH 800
# define W_HEIGHT 600

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

typedef struct 			s_julia
{
	long double			cRe;
	long double			cIm;
	long double			newRe;
	long double			newIm;
	long double			oldRe;
	long double			oldIm;
	long double			zoom;
	long double			moveX;
	long double			moveY;
	long double			time;
	long double			oldtime;
	long double			frameTime;

}						t_julia;

void        mandelbrot(t_env *e);
void		julia(t_env *e);
int         get_color(unsigned int n, unsigned int max_iter);
#endif