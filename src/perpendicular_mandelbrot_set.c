/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perpendicular_mandelbrot.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:40:41 by arrudenk          #+#    #+#             */
/*   Updated: 2018/05/08 18:40:42 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		perpen_mandelbrot_part2(t_fractal *set)
{
	double	x_t;
	double	y_t;
	double	temp;

	set->real = (set->x - W / 2) / (0.25 * set->zoom * W) + set->x_move;
	x_t = 0;
	y_t = 0;
	set->thing = 0;
	while (x_t * x_t + y_t * y_t <= 4 && set->thing < set->maximum)
	{
		temp = x_t * x_t - y_t * y_t + set->real;
		y_t = y_t * fabs(x_t) * -2 + set->imaginary;
		x_t = temp;
		set->thing++;
	}
	if (set->thing < set->maximum)
		pixel_to_image(set);
}

void		perpen_mandel_set(t_fractal *set)
{
	set->y = set->start;
	while (set->y < set->end)
	{
		set->x = 0;
		set->imaginary =
				(set->y - H / 2) / (0.25 * set->zoom * H) + set->y_move;
		while (set->x < W)
		{
			perpen_mandelbrot_part2(set);
			set->x++;
		}
		set->y++;
	}
	pthread_exit(0);
}

void		perpen_mandelbrot(t_fractal *set)
{
	pthread(set);
	mlx_hook(set->mlx->win, 2, 5, hook_keydown, set);
	mlx_mouse_hook(set->mlx->win, mouse_func, set);
	mlx_hook(set->mlx->win, 17, 1L << 17, exit_x, set->mlx->mlx);
	mlx_put_image_to_window(set->mlx->mlx, set->mlx->win
			, set->mlx->img->image, 0, 0);
}
