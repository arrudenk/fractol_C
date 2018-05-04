/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:25:17 by arrudenk          #+#    #+#             */
/*   Updated: 2018/05/04 19:25:19 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		celtic_part2(t_fractal *fractal)
{
	double	x_t;
	double	y_t;
	double	temp;

	fractal->real = (fractal->x - W / 2) /
					(0.25 * fractal->zoom * W) + fractal->x_move;
	x_t = 0;
	y_t = 0;
	fractal->thing = 0;
	while (x_t * x_t + y_t * y_t <= 4 && fractal->thing < fractal->maximum)
	{
		temp = fabs(x_t * x_t - y_t * y_t) + fractal->real;

		y_t = y_t * x_t * 2 + fractal->imaginary;
		x_t = temp;
		fractal->thing++;
	}
	if (fractal->thing < fractal->maximum)
		pixel_to_image(fractal);
}

static void		celtic_mandelbrot(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < H)
	{
		fractal->x = 0;
		fractal->imaginary = (fractal->y - H / 2) / (0.25 * fractal->zoom * H) + fractal->y_move;
		while (fractal->x < W)
		{
			celtic_part2(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
}

void		celtic(t_fractal *set)
{
	celtic_mandelbrot(set);
	mlx_hook(set->mlx->win, 2, 5, hook_keydown, set);
	mlx_mouse_hook(set->mlx->win, mouse_func, set);
	mlx_hook(set->mlx->win, 17, 1L << 17, exit_x, set->mlx->mlx);
	mlx_put_image_to_window(set->mlx->mlx, set->mlx->win, set->mlx->img->image, 0, 0);
}
