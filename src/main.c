/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:42:03 by arrudenk          #+#    #+#             */
/*   Updated: 2018/05/08 16:42:05 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		exit_x(void)
{
	exit(123);
}

void	error(int error)
{
	if (error == -1)
		ft_putendl("Bad argument. Available (-j (<-Julia set)"
						", -m (<-Mandelbrot), -c (<-Celtic))");
	exit(error);
}

int		main(int argc, char **argv)
{
	t_fractal *fractal;

	fractal = fractal_info();
	if (argc != 2)
		error(-1);
	select_fractal(argv[1], fractal);
	do_fractal(fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_loop(fractal->mlx->mlx);
	return (0);
}
