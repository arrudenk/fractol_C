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
	update(set);
	return (0);
}

int			hook_keydown(int key, t_fractal *set)
{
	change_color(set, key);
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
		if (set->stop == 0)
			set->stop = 1;
		else
			set->stop = 0;
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
			set->zoom /= 1.2;
		else if(set->zoom >= 1.2)
			set->zoom *= 1.2;
	}
	if (key == MAC_RANDOM)
	{
		set->x_move = 0;
		set->zoom = 1;
		set->y_move = 0;
		set->red = 0;
		set->green = 0;
		set->blue = 0;
	}
	update(set);
	return (0);
}
