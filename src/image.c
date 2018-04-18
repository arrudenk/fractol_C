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
