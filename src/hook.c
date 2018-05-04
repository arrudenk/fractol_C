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

int		mouse_func(int button, int x, int y, t_fractal *set)
{
	clear_image(set->mlx);
	if (button == 4)
	{
		set->zoom *= 1.1;
		set->y_move -= (((float)(H / 2) - y) / (H * set->zoom));
		set->x_move -= (((float)(W / 2) - x) / (W * set->zoom));
	}
	if (button == 5)
	{
		set->zoom /= 1.1;
		set->y_move -= (((float)(H / 2) - y) / (H * set->zoom));
		set->x_move -= (((float)(W / 2) - x) / (W * set->zoom));
	}
	do_fractal(set);
	mlx_put_image_to_window(set->mlx, set->mlx->win, set->mlx->img, 0, 0);
	return (0);
}

int			hook_keydown(int key, t_fractal *set)
{
	if (key == ESC)
		exit(123);
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			set->x_move += 0.002;
		else
			set->x_move -= 0.002;
	}
	if (key == Q || key == E)
	{
		set->stop = set->stop == 0 ? 1 : 0;
	}
	if (key == UP || key == DOWN)
	{
		if (key == UP)
			set->y_move += 0.02;
		else
			set->y_move -= 0.02;
	}
	if (key == MINUS || key == PLUS)
	{
		if (key == PLUS)
			set->zoom += 1.2;
		else if(set->zoom >= 2.2)
			set->zoom += -1.2;
	}
	if (key == MAC_RANDOM)
	{
		set->x_move = 0;
		set->zoom = 1;
		set->y_move = 0;

	}
	update(set);
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
