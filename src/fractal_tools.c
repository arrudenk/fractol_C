/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:35:08 by arrudenk          #+#    #+#             */
/*   Updated: 2018/05/08 16:35:09 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		update(t_fractal *set)
{
	clear_image(set->mlx);
	do_fractal(set);
}

void		do_fractal(t_fractal *set)
{
	if (set->fractal == 1)
		mandelbrot(set);
	else if (set->fractal == 2)
		julia(set);
	else if (set->fractal == 3)
		celtic(set);
	else if (set->fractal == 4)
		tricorn(set);
	else if (set->fractal == 5)
		perpen_mandelbrot(set);
	else if (set->fractal == 6)
		perpen_celtic(set);
	else if (set->fractal == 7)
		heart(set);
	else if (set->fractal == 8)
		four_mandelbrot(set);
}

void		select_fractal(const char *str, t_fractal *fractal)
{
	if (str[0] == '-')
	{
		if (ft_strequ("-m", str))
			fractal->fractal = (1);
		else if (ft_strequ("-j", str))
			fractal->fractal = (2);
		else if (ft_strequ("-c", str))
			fractal->fractal = (3);
		else if (ft_strequ("-t", str))
			fractal->fractal = (4);
		else if (ft_strequ("-pm", str))
			fractal->fractal = (5);
		else if (ft_strequ("-pc", str))
			fractal->fractal = (6);
		else if (ft_strequ("-h", str))
			fractal->fractal = (7);
		else if (ft_strequ("-4m", str))
			fractal->fractal = (8);
		else
			error(-1);
	}
	else
		error(-1);
}

t_fractal	*fractal_info(void)
{
	t_fractal	*set;

	set = ft_memalloc(sizeof(t_fractal));
	set->mlx = init_mlx();
	set->thing = 0;
	set->maximum = 30;
	set->zoom = 1;
	set->x_move = 0;
	set->y_move = 0;
	set->red = 10;
	set->green = 10;
	set->blue = 10;
	set->start = 0;
	set->end = 0;
	ft_putendl("\n\tKeys:\n\tcolor: R G B;\n\titerations: ↑ UP | ↓ DOWN;"
					"\n\tReset: =\n\tJulia mouse stop: Q");
	return (set);
}
