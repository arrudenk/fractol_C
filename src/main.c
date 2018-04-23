/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42->fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:49:27 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/16 17:49:29 by arrudenk         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keyx.h"
#include <stdio.h>

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

void		pixel_to_image(t_fractal *fractal)
{
	int j;
	j = 4 * (fractal->y * W + fractal->x);
	fractal->mlx->img->ptr[j] = 42 * fractal->iterator / 42;
	fractal->mlx->img->ptr[j + 1] = 42 * 42 * fractal->iterator / 42;
	fractal->mlx->img->ptr[j + 2] = 42 * 42 * 42 * fractal->iterator / 42;
}

void		mandelbrod_part2(t_fractal *fractal)
{
	double	x_t;
	double	y_t;
	double	tem;

	fractal->real = (fractal->x - W / 2) /
				(0.25 * fractal->zoom * W) + fractal->x_move;
	x_t = 0;
	y_t = 0;
	fractal->iterator = 0;
	while (x_t * x_t + y_t * y_t <= 4 && fractal->iterator < fractal->max_iterations)
	{
		tem = x_t * x_t - y_t * y_t + fractal->real;

		y_t = 2 * y_t * x_t + fractal->imaginary;
		x_t = tem; // x_t * x_t - y_t * y_t + fractal->real;
//		printf("%f %f \n", y_t, x_t);
		fractal->iterator++;
	}
	if (fractal->iterator < fractal->max_iterations)
		pixel_to_image(fractal);

}

void		mandelbrod_part1(t_fractal *fractal)
{
	fractal->y = 0;
	while (fractal->y < fractal->mlx->h)
	{
		fractal->x = 0;
		fractal->imaginary = (fractal->y - H / 2) / (0.25 * fractal->zoom * H) + fractal->y_move;
		while (fractal->x < fractal->mlx->h)
		{
			mandelbrod_part2(fractal);
			fractal->x++;
		}
		fractal->y++;
	}
	mlx_put_image_to_window(fractal->mlx->mlx, fractal->mlx->win, fractal->mlx->img->image, 0, 0);
}


int			hook_keydown(int key, t_fractal *fractal)
{
	if (key == ESC)
		exit(123);
	if (key == LEFT || key == RIGHT)
	{
		;
	}
	if (key == Q || key == E)
	{
		;
	}
	if (key == UP || key == DOWN)
	{
		;
	}
	if (key == MINUS || key == PLUS)
	{
		;
	}
	if (key == MAC_RANDOM)
	{
		;
	}
	return (0);
}

t_fractal	*fractal_info(void)
{
	t_fractal	*fractal;

	fractal = ft_memalloc(sizeof(t_fractal));
	fractal->mlx = init_mlx();
	fractal->iterator = 0;
	fractal->max_iterations = 130;
	fractal->zoom = 1;
	fractal->x_move = -0.5;
	fractal->y_move = 0;
	return (fractal);
}

int		main(int argc, char **argv)
{
//	if (argc != 2)
//		return (2);
	t_fractal	*fractal;

	fractal = fractal_info();
	mandelbrod_part1(fractal);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, &fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_loop(fractal->mlx->mlx);
	return (0);
}
