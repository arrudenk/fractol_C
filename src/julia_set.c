/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:10:46 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/24 11:10:48 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		mouse_julia(int x, int y, t_fractal *fractal)
{
	clear_image(fractal->mlx);
	fractal->real = (x - W / 2)
					/ (0.25 * fractal->zoom * W) + fractal->x_move;
	fractal->imaginary = (y - H / 2)
						 / (0.25 * fractal->zoom * H) + fractal->y_move;
	fractal->x = x;
	fractal->x = y;
	do_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx->win, fractal->mlx->img, 0, 0);
	return (0);
}

static void	julia_pixel(t_fractal *fractal)
{
	double	x_t;
	double	y_t;
	double	temp;

	x_t = (fractal->x - W / 2) / (0.25 * W * fractal->zoom) + fractal->x_move;
	y_t = (fractal->y - H / 2) / (0.25 * H * fractal->zoom) + fractal->y_move;
	fractal->thing = 0;
	while (x_t * x_t + y_t * y_t <= 4 && fractal->thing < fractal->maximum)
	{
		temp = x_t * x_t - y_t * y_t + fractal->real;
		y_t = 2 * x_t * y_t + fractal->imaginary;
		x_t = temp;
		fractal->thing++;
	}
	if (fractal->thing < fractal->maximum)
		pixel_to_image(fractal);
}

static void		juli_do_the_thing(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < H)
	{
		fractal->x = 0;

		while (fractal->x < W)
		{
			julia_pixel(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
}

void		julia(t_fractal *fractal)
{
	juli_do_the_thing(fractal);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_hook(fractal->mlx->win, 6, 1L < 6, mouse_julia, fractal);
	mlx_mouse_hook(fractal->mlx->win, mouse_func, fractal);
	mlx_put_image_to_window(fractal->mlx->mlx, fractal->mlx->win, fractal->mlx->img->image, 0, 0);

}