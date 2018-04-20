/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:49:27 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/16 17:49:29 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keyx.h"

int			exit_x(void *win_ptr)
{
	exit(123);
}

double	dot_vec4(t_vec4 v1, t_vec4 v2)
{
	double r;

	r = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w + v1.f * v2.f;
	return (r);
}

void		mandelbrod_part2(t_fractal fractal)
{
	double	x_t;
	double	y_t;
	double	tem;

	fractal.real = (fractal.x - W / 2) /
				(0.25 * fractal.zoom * W);
	x_t = 0;
	y_t = 0;
	fractal.iterator = 0;
	while (x_t * x_t + y_t * y_t <= 4 && fractal.iterator < fractal.max_iterations)
	{
		tem = x_t * x_t - y_t * y_t + fractal.real;
		y_t = 2 * x_t * y_t + fractal.not_real;
		x_t = tem;
		image_set_pixel(fractal.mlx, (int)y_t, (int)x_t, 0xffffff);
		ft_putnbr(x_t);
		ft_putchar('\n');
		fractal.iterator++;
	}
//	if (fractal.iterator < fractal.max_iterations)
//		pixel_image_put(frac);

}

void		mandelbrod_part1(t_fractal fractal)
{
	fractal.x = 0;
	while (fractal.x < fractal.mlx->h)
	{
		fractal.y = 0;
		fractal.not_real = (fractal.y - H / 2) /
					 (0.25 * fractal.zoom * H);
		while (fractal.y < fractal.mlx->w)
		{
			mandelbrod_part2(fractal);
			fractal.y++;
		}
		fractal.x++;
	}

	mlx_put_image_to_window(fractal.mlx->mlx, fractal.mlx->win, fractal.mlx->img->image, 0, 0);
}


int			hook_keydown(int key, t_fractal *fractal)
{
	if (key == ESC)
		exit(123);
	if (key == LEFT || key == RIGHT)
		;
	if (key == Q || key == E)
		;
	if (key == UP || key == DOWN)
		;
	if (key == MINUS || key == PLUS)
		;
	if (key == MAC_RANDOM)
	{
		;
	}
	return (0);
}

t_fractal	fractal_info()
{
	t_fractal	fractal;

	fractal.mlx = init_mlx();
	fractal.iterator = 0;
	fractal.max_iterations = 100;
	fractal.zoom = 1;
	fractal.x_move = 0;
	fractal.y_move = 0;
	return (fractal);
}

int		main(int argc, char **argv)
{
//	if (argc != 2)
//		return (2);
	t_fractal	fractal;

	fractal = fractal_info();
	mandelbrod_part1(fractal);
	mlx_hook(fractal.mlx->win, 2, 5, hook_keydown, &fractal);
	mlx_hook(fractal.mlx->win, 17, 1L << 17, exit_x, fractal.mlx->mlx);
	mlx_loop(fractal.mlx->mlx);
	return (0);
}
