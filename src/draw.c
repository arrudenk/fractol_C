/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:50:33 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/16 17:50:36 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keyx.h"

void			change_color(t_fractal *set, int key)
{
	if (key == RED)
		set->red += 10;
	if (key == GREEN)
		set->green += 10;
	if (key == BLUE)
		set->blue += 10;
	ft_putstr("red: ");
	ft_putnbr(set->red);
	ft_putstr(" green: ");
	ft_putnbr(set->green);
	ft_putstr(" blue: ");
	ft_putnbr(set->blue);
	ft_putendl("");
}