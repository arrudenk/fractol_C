/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:36:20 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/18 12:36:23 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	image_set_pixel(t_mlx *mlx, int x, int y, int c)
{
	*(int *)(mlx->img->ptr + ((x + y * W) * mlx->img->bpp)) = c;
}

void	clear_image(t_mlx *mlx)
{
	int		i;

	i = W * H * mlx->img->bpp;
	while (--i)
		*(mlx->img->ptr + i) = 0;
	*(mlx->img->ptr) = 0;
}

void	pixel_to_image(t_fractal *fractal)
{
	int j;
	j = 4 * ((int)fractal->y * W + (int)fractal->x);
	fractal->mlx->img->ptr[j] = 32 * fractal->thing;
	fractal->mlx->img->ptr[j + 1] = 8 * fractal->thing;
	fractal->mlx->img->ptr[j + 2] = 25 * fractal->thing;
}

t_image	*new_image(t_mlx *mlx)
{
	t_image	*img;

	if (!(img = (t_image *)malloc(sizeof(t_image))))
	{
		ft_putendl("error");
		exit(1);
	}
	if (!(img->image = mlx_new_image(mlx->mlx, W, H)))
	{
		ft_putendl("error");
		exit(1);
	}
	img->ptr = mlx_get_data_addr(img->image, &(img->bpp), &(img->stride)
			, &(img->endian));
	img->bpp = (img->bpp) >> 3;
	return (img);
}

t_image	*create_new_im(void *mlx)
{
	t_image *im;

	im = (t_image *)malloc(sizeof(t_image));
	im->image = mlx_new_image(mlx, W, H);
	im->ptr = mlx_get_data_addr(im->image, &im->bpp, &im->stride, &im->endian);
	im->bpp /= 8;
	return (im);
}