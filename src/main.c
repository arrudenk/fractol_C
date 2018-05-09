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
		ft_putendl("ERROR->Bad argument. Available "
						"\n\t1) -j\t(<-Julia set)"
						"\n\t2) -m\t(<-Mandelbrot)"
						"\n\t3) -c\t(<-Celtic)"
						"\n\t4) -t\t(<-Tricorn)"
						"\n\t5) -pm\t(<-perpendicular Mandelbrot)"
						"\n\t6) -pc\t(<-perpendicular Celtic)"
						"\n\t7) -h\t(<-Heart)"
						"\n\t8) -4m\t(<-Mandelbrot 4th Order)");
	exit(error);
}

int		main(int argc, char **argv)
{
	t_fractal	*fractal;
	char		*temp;

	if (argc < 2)
		error(-1);
	if (argc > 2)
	{
		temp = ft_strjoin("./fractol ", ft_strjoin(argv[2], " &"));
		system(temp);
	}
	fractal = fractal_info();
	select_fractal(argv[1], fractal);
	do_fractal(fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_loop(fractal->mlx->mlx);
	return (0);
}
