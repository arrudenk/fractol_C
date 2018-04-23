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
#include "../includes/keyx.h"
#include <stdio.h>

int			exit_x(void)
{
	exit(123);
}

void		update(t_fractal *fractal)
{
	clear_image(fractal->mlx);
	mandelbrod_part1(fractal);
}

int			hook_keydown(int key, t_fractal *fractal)
{
	static double zoomer = 0.5;
	if (key == ESC)
		exit(123);
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			fractal->x_move += 0.002;
		else
			fractal->x_move -= 0.002;
	}
	if (key == Q || key == E)
	{
		;
	}
	if (key == UP || key == DOWN)
	{
		if (key == UP)
			fractal->y_move += 0.02;
		else
			fractal->y_move -= 0.02;
	}
	if (key == MINUS || key == PLUS)
	{
		if (key == PLUS)
			fractal->zoom += 1.2;
		else if(fractal->zoom >= 2.2)
			fractal->zoom += -1.2;
	}
	if (key == MAC_RANDOM)
	{
		fractal->x_move = 0;
		fractal->zoom = 1;
		fractal->y_move = 0;

	}
	update(fractal);
	return (0);
}

t_fractal	*fractal_info(void)
{
	t_fractal	*fractal;

	fractal = ft_memalloc(sizeof(t_fractal));
	fractal->mlx = init_mlx();
	fractal->iterator = 0;
	fractal->max_iterations = 255;
	fractal->zoom = 1;
	fractal->x_move = 0;
	fractal->y_move = 0;
	return (fractal);
}

int		main(int argc, char **argv)
{
//	if (argc != 2)
//		return (2);
	t_fractal	*fractal;
//	cl_platform_id platform_id = NULL;
//	cl_device_id device_id = NULL;
//	cl_uint ret_num_devices;
//	cl_uint ret_num_platforms;
//	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
//	ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1,
//						  &device_id, &ret_num_devices);
	// Create an OpenCL context
//	cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);
//
//	// Create a command queue
//	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

	fractal = fractal_info();
	mandelbrod_part1(fractal);
	mlx_hook(fractal->mlx->win, 2, 5, hook_keydown, fractal);
	mlx_hook(fractal->mlx->win, 17, 1L << 17, exit_x, fractal->mlx->mlx);
	mlx_loop(fractal->mlx->mlx);
	return (0);
}
