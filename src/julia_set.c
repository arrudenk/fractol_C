/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 11:10:46 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/24 11:10:48 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		mouse_julia(int x, int y, t_fractal *set)
{
	if (set->stop == 0)
	{
		set->real =
				(x - W / 2) / (0.25 * set->zoom * W) + set->x_move;
		set->imaginary =
				(y - H / 2) / (0.25 * set->zoom * H) + set->y_move;
		set->x = x;
		set->x = y;
	}
	update(set);
//	mlx_put_image_to_window(set->mlx, set->mlx->win, set->mlx->img, 0, 0);
	return (0);
}

static void		julia_pixel(t_fractal *set)
{
	double	x_t;
	double	y_t;
	double	temp;

	x_t = (set->x - W / 2) / (0.25 * W * set->zoom) + set->x_move;
	y_t = (set->y - H / 2) / (0.25 * H * set->zoom) + set->y_move;
	set->thing = 0;
	while (x_t * x_t + y_t * y_t <= 4 && set->thing < set->maximum)
	{
		temp = x_t * x_t - y_t * y_t + set->real;
		y_t = 2 * x_t * y_t + set->imaginary;
		x_t = temp;
		set->thing++;
	}
	if (set->thing < set->maximum)
		pixel_to_image(set);
}

void		juli_do_the_thing(t_fractal *set)
{
	set->y = set->start;
	while (set->y < set->end)
	{
		set->x = 0;
		while (set->x < set->end)
		{
			julia_pixel(set);
			set->x++;
		}
		set->y++;
	}
}

void		julia(t_fractal *set)
{
	pthread(set);
	mlx_hook(set->mlx->win, 2, 5, hook_keydown, set);
	mlx_hook(set->mlx->win, 6, 1L < 6, mouse_julia, set);
	mlx_mouse_hook(set->mlx->win, mouse_func, set);
	mlx_put_image_to_window(set->mlx->mlx, set->mlx->win, set->mlx->img->image
			, 0, 0);
}