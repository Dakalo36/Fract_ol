/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnematan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:33:30 by dnematan          #+#    #+#             */
/*   Updated: 2016/10/05 15:33:34 by dnematan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void    error_log(void)
{
    ft_putstr("Fractol Usage: ./fractol mandelbrot | julia");
    ft_putchar('\n');
}

void    ft_init(t_env *env, char *name)
{
    env->mlx = mlx_init();
    env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, name);
    env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
    env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line), &(env->ind));

}

int     main(int argc, char **argv)
{
    t_env   env;

    if (argc == 2)
    {
        ft_init(&env, "Fract_ol WTC");
        if (ft_strcmp(argv[1], "mandelbrot") == 0)
        {
            env.fractol = mandelbrot;
            env.fractol(&env);
        }
        else
            error_log();
    }
    else
        error_log();
    return (0);
}
