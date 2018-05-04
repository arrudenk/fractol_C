/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:34:52 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/24 12:34:54 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keyx.h"

int		mouse_func(int button, int x, int y, t_fractal *fractal)
{
	clear_image(fractal->mlx);
	if (button == 4)
	{
		fractal->zoom *= 1.1;
		fractal->y_move -= (((float)(H / 2) - y) / (H * fractal->zoom));
		fractal->x_move -= (((float)(W / 2) - x) / (W * fractal->zoom));
	}
	if (button == 5)
	{
		fractal->zoom /= 1.1;
		fractal->y_move -= (((float)(H / 2) - y) / (H * fractal->zoom));
		fractal->x_move -= (((float)(W / 2) - x) / (W * fractal->zoom));
	}
	do_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx->win, fractal->mlx->img, 0, 0);
	return (0);
}

int			hook_keydown(int key, t_fractal *fractal)
{
	if (key == ESC)
		exit(123);
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			fractal->x_move += 0.002;
		else
			fractal->x_move -= 0.002;
	}
	if (key == Q || key == E)
	{
		fractal->stop = fractal->stop == 0 ? 1 : 0;
	}
	if (key == UP || key == DOWN)
	{
		if (key == UP)
			fractal->y_move += 0.02;
		else
			fractal->y_move -= 0.02;
	}
	if (key == MINUS || key == PLUS)
	{
		if (key == PLUS)
			fractal->zoom += 1.2;
		else if(fractal->zoom >= 2.2)
			fractal->zoom += -1.2;
	}
	if (key == MAC_RANDOM)
	{
		fractal->x_move = 0;
		fractal->zoom = 1;
		fractal->y_move = 0;

	}
	update(fractal);
	return (0);
}

int		mouse_julia(int x, int y, t_fractal *fractal)
{
	clear_image(fractal->mlx);
	if (fractal->stop == 0)
	{
		fractal->real = (x - W / 2)
						/ (0.25 * fractal->zoom * W) + fractal->x_move;
		fractal->imaginary = (y - H / 2)
							 / (0.25 * fractal->zoom * H) + fractal->y_move;
		fractal->x = x;
		fractal->x = y;
	}

	if (fractal->fractal == 2)
		do_fractal(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->mlx->win, fractal->mlx->img, 0, 0);
	return (0);
}
