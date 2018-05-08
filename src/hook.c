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

int				mouse_func(int button, int x, int y, t_fractal *set)
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

static void		change_color(t_fractal *set, int key)
{
	if (key == RED)
		set->red = set->red + 5;
	if (key == GREEN)
		set->green = set->green + 5;
	if (key == BLUE)
		set->blue = set->blue + 5;
	ft_putstr("red: ");
	ft_putnbr(set->red);
	ft_putstr(" green: ");
	ft_putnbr(set->green);
	ft_putstr(" blue: ");
	ft_putnbr(set->blue);
	ft_putendl("");
}

static void		change_maximum(t_fractal *set, int key)
{
	if (key == ARROW_UP)
		set->maximum += 10;
	else if (key == ARROW_DOWN)
		set->maximum -= 10;
}

static void		change_position(t_fractal *set, int key)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			set->x_move += 0.002;
		else
			set->x_move -= 0.002;
	}
	else if (key == UP || key == DOWN)
	{
		if (key == UP)
			set->y_move += 0.02;
		else
			set->y_move -= 0.02;
	}
}

int				hook_keydown(int key, t_fractal *set)
{
	change_color(set, key);
	change_maximum(set, key);
	change_position(set, key);
	if (key == ESC)
		exit(123);
	if (key == Q)
		set->stop = (set->stop == 0) ? 1 : 0;
	if (key == MINUS || key == PLUS)
		if (key == PLUS)
			set->zoom /= 1.2;
		else if (set->zoom >= 1.2)
			set->zoom *= 1.2;
	if (key == MAC_RANDOM)
	{
		set->x_move = 0;
		set->zoom = 1;
		set->y_move = 0;
		set->red = 42;
		set->green = 42 + 42;
		set->blue = 42 + 42;
	}
	update(set);
	return (0);
}
