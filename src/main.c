/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main->c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42->fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:49:27 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/16 17:49:29 by arrudenk         ###   ########->fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

int			exit_x(void)
{
	exit(123);
}

void		update(t_fractal *set)
{
	clear_image(set->mlx);
	do_fractal(set);
}


t_fractal	*fractal_info(void)
{
	t_fractal	*fractal;

	fractal = ft_memalloc(sizeof(t_fractal));
	fractal->mlx = init_mlx();
	fractal->thing = 0;
	fractal->maximum = 200;
	fractal->zoom = 1;
	fractal->x_move = 0;
	fractal->y_move = 0;
	return (fractal);
}

void	do_fractal(t_fractal *set)
{
	if (set->fractal == 1)
		mandelbrot(set);
	else if (set->fractal == 2)
		julia(set);
	else if (set->fractal == 3)
		celtic(set);
	else if (set->fractal == 4)
		;
	else if (set->fractal == 5)
		;
}

void		select_fractal(const char *str, t_fractal *fractal)
{
	if (str[0] == '-')
	{
		if (str[1] == 'm')
			fractal->fractal = (1);
		else if (str[1] == 'j')
			fractal->fractal = (2);
		else if (str[1] == 'c')
			fractal->fractal = (3);
		else if (str[1] == 'p')
			fractal->fractal = (4);
		else if (str[1] == 't')
			fractal->fractal = (5);
		else if (str[1] == 'k')
			fractal->fractal = (6);
		else if (str[1] == 'b')
			fractal->fractal = (7);
		else
			fractal->fractal = 0;
	}
	else
	{
		fractal->fractal = 0;
	}
}

int		main(int argc, char **argv)
{
	t_fractal *fractal;

	fractal = fractal_info();
	if (argc != 2)
		return (2);
	select_fractal(argv[1], fractal);
	do_fractal(fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_loop(fractal->mlx->mlx);
	return (0);
}
