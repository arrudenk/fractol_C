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
	t_fractal	c_arr[THREADS];
	pthread_t	tid[THREADS];

	i = 0;
	while (i < THREADS && (ft_memcpy((void*)&c_arr[i], set, sizeof(t_fractal))))
	{
		c_arr[i].start = i * (W / THREADS);
		c_arr[i].end = (i + 1) * (W / THREADS);
		i++;
	}
	i = -1;
	while (++i < THREADS)
	{
		if (set->fractal == 1)
			pthread_create(&tid[i], NULL, mandelbrot_set, &c_arr[i]);
		if (set->fractal == 2)
			pthread_create(&tid[i], NULL, juli_do_set, &c_arr[i]);
		if (set->fractal == 3)
			pthread_create(&tid[i], NULL, celtic_set, &c_arr[i]);
		if (set->fractal == 4)
			pthread_create(&tid[i], NULL, tricorn_set, &c_arr[i]);
		if (set->fractal == 5)
			pthread_create(&tid[i], NULL, perpen_mandelbrot_set, &c_arr[i]);
		if (set->fractal == 6)
			pthread_create(&tid[i], NULL, perpen_celtic_set, &c_arr[i]);
		if (set->fractal == 7)
			pthread_create(&tid[i], NULL, heart_set, &c_arr[i]);
		if (set->fractal == 8)
			pthread_create(&tid[i], NULL, four_mandelbrot_set, &c_arr[i]);
	}
	while (--i >= 0)
		pthread_join(tid[i], NULL);
}
