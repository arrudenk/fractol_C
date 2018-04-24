/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:19:51 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/23 14:19:56 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		mandelbrod_part2(t_fractal *fractal)
{
	double	x_t;
	double	y_t;
	double	tem;

	fractal->real = (fractal->x - W / 2) /
					(0.25 * fractal->zoom * fractal->mlx->w) + fractal->x_move;
	x_t = 0;
	y_t = 0;
	fractal->thing = 0;
	while (x_t * x_t + y_t * y_t <= 4 && fractal->thing < fractal->maximum)
	{
		tem = x_t * x_t - y_t * y_t + fractal->real;

		y_t = 2 * y_t * x_t + fractal->imaginary;
		x_t = tem; // x_t * x_t - y_t * y_t + fractal->real;
//		printf("%f %f \n", y_t, x_t);
		fractal->thing++;
	}
	if (fractal->thing < fractal->maximum)
		pixel_to_image(fractal);

}

static void		mandelbrod_set(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < fractal->mlx->h)
	{
		fractal->x = 0;
		fractal->imaginary = (fractal->y - fractal->mlx->h / 2) / (0.25 * fractal->zoom * fractal->mlx->h) + fractal->y_move;
		while (fractal->x < fractal->mlx->h)
		{
			mandelbrod_part2(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
//	mlx_put_image_to_window(fractal->mlx->mlx, fractal->mlx->win, fractal->mlx->img->image, 0, 0);
}

void		mandelbrod(t_fractal *fractal)
{
	mandelbrod_set(fractal);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_put_image_to_window(fractal->mlx->mlx, fractal->mlx->win, fractal->mlx->img->image, 0, 0);
}