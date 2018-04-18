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
	exit(1);
}

void		fill_window()
{


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

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (2);
	t_mlx	*mlx;
	t_fractal fractal;
	mlx = init_mlx();
	fractal.mlx = mlx;

	fill_window();
	mlx_hook(fractal.mlx->win, 2, 5, hook_keydown, &fractal);
	mlx_hook(fractal.mlx->win, 17, 1L << 17, exit_x, fractal.mlx->mlx);
	mlx_loop(fractal.mlx->mlx);
	return (0);
}
