/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_optimization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:55:58 by arrudenk          #+#    #+#             */
/*   Updated: 2018/05/07 18:56:00 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		pthread(t_fractal *set)
{
	int			i;
	t_fractal	c_arr[4];
	pthread_t	tid[THREADS];

	i = -1;
	while (++i < THREADS && (ft_memcpy((void*)&c_arr[i], set, sizeof(t_fractal))))
	{
		c_arr[i].start = i * 200;
		c_arr[i].end = (i + 1) * 200;
	}
	i = -1;
	while (++i < THREADS)
	{
		if (set->fractal == 1)
			pthread_create(&tid[i], NULL, mandelbrot_set, &c_arr[i]);
		if (set->fractal == 2)
			pthread_create(&tid[i], NULL, juli_do_the_thing, &c_arr[i]);
		if (set->fractal == 3)
			pthread_create(&tid[i], NULL, celtic_mandelbrot, &c_arr[i]);
	}
	while (--i >= 0)
		pthread_join(tid[i], NULL);
	mlx_put_image_to_window(set->mlx->mlx, set->mlx->win, set->mlx->img->pic, 0, 0);
}

