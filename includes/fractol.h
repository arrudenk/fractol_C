/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:49:40 by arrudenk          #+#    #+#             */
/*   Updated: 2018/04/16 17:49:42 by arrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_C_H
# define FRACTOL_C_H
# include "mlx.h"
# include "libft.h"
# define W 640
# define H 480

typedef struct	s_image
{
	void	*image;
	char	*ptr;
	int		bpp;
	int		stride;
	int		endian;
}				t_image;

typedef	struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_image	*img;
}				t_mlx;

typedef struct	s_fractal
{
	t_mlx	*mlx;
}				t_fractal;

t_image		*new_image(t_mlx *mlx);
void		clear_image(t_mlx *mlx);
t_mlx		*init_mlx(void);


#endif
