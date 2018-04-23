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
# include "math.h"
# include "OpenCL/opencl.h"

# define W 640
# define H 640

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
	void		*mlx;
	void		*win;
	t_image		*img;
	double		w;
	double		h;
}				t_mlx;

typedef struct	s_fractal
{
	t_mlx		*mlx;
	double		imaginary;
	double		real;
	int			iterator;
	int			max_iterations;
	double		zoom;
	double		x;
	double		y;
	double		x_move;
	double		y_move;
}				t_fractal;

t_image		*new_image(t_mlx *mlx);
t_image		*create_new_im(void *mlx);
void		clear_image(t_mlx *mlx);
void		image_set_pixel(t_mlx *mlx, int x, int y, int c);
t_mlx		*init_mlx(void);
void		pixel_to_image(t_fractal *fractal);
void		mandelbrod_part1(t_fractal *fractal);


#endif
