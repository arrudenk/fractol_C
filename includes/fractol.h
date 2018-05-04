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

# define W 500
# define H 500

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
}				t_mlx;

typedef struct	s_fractal
{
	t_mlx		*mlx;
	double		imaginary;
	double		real;
	int			thing;
	int			maximum;
	double		zoom;
	double		x;
	double		y;
	int			stop;
	int			fractal;
	double		x_move;
	double		y_move;
}				t_fractal;

int			exit_x(void);
t_image		*new_image(t_mlx *mlx);

//mandatory ->
void		mandelbrot(t_fractal *set);
void		julia(t_fractal *set);
void		celtic(t_fractal *set);
// <-
void		update(t_fractal *set);
//keys
int			hook_keydown(int key, t_fractal *set);
//<-
void		do_fractal(t_fractal *set);
t_image		*create_new_im(void *mlx);
void		clear_image(t_mlx *mlx);
void		image_set_pixel(t_mlx *mlx, int x, int y, int c);
t_mlx		*init_mlx(void);
void		pixel_to_image(t_fractal *set);

//BONUS ->
int			mouse_func(int button, int x, int y, t_fractal *set);
void		zoomin(t_fractal *set, int x, int y);


#endif
