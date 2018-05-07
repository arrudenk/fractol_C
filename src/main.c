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
	t_fractal	*set;

	set = ft_memalloc(sizeof(t_fractal));
	set->mlx = init_mlx();
	set->thing = 0;
	set->maximum = 200;
	set->zoom = 1;
	set->x_move = 0;
	set->y_move = 0;
	set->red = 0;
	set->green = 0;
	set->blue = 0;
	return (set);
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
}

void		error(int error)
{
	if (error == -1)
		ft_putendl("Bad argument. Available (-j (<-Julia set)"
						   ", -m (<-Mandelbrot), -c (<-Celtic))");
	exit(error);
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
		else
			error(-1);
	}
	else
		error(-1);
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
