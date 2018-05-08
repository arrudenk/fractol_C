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

void	pixel_to_image(t_fractal *set)
{
	int j;
	j = 4 * ((int)set->y * W + (int)set->x);
	set->mlx->img->pic[j] = (char)set->blue * (char)set->thing;
	set->mlx->img->pic[j + 1] = (char)set->green * (char)set->thing;
	set->mlx->img->pic[j + 2] = (char)set->red * (char)set->thing;
}

t_image	*new_image(t_mlx *mlx)
{
	t_image *img;

	img = (t_image *)malloc(sizeof(t_image));
	img->image = mlx_new_image(mlx, W, H);
	img->pic = mlx_get_data_addr(img->image, &img->bpp, &img->stride, &img->endian);
	img->bpp /= 8;
	return (img);
}

void	clear_image(t_mlx *mlx)
{
	ft_bzero(mlx->img->pic, W * H * mlx->img->bpp);
}