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
# include <pthread.h>

# define W 800
# define H 800
# define THREADS 4

typedef struct	s_image
{
	void		*image;
	char		*pic;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*img;
}				t_mlx;

typedef struct	s_fractal
{
	t_mlx	*mlx;
	double	imaginary;
	double	real;
	int		thing;
	int		maximum;
	double	zoom;
	double	x;
	double	y;
	int		stop;
	int		fractal;
	double	x_move;
	double	y_move;
	int		red;
	int		green;
	int		blue;
	int		start;
	int		end;
}				t_fractal;

int				exit_x(void);
/*>>>>MLX<<<<*/
t_mlx			*init_mlx(void);
t_image			*new_image(t_mlx *mlx);
t_image			*create_new_im(void *mlx);
void			image_set_pixel(t_mlx *mlx, int x, int y, int c);
void			pixel_to_image(t_fractal *set);
void			clear_image(t_mlx *mlx);
/*>>FRACTALS_SHT<<*/
void			mandelbrot(t_fractal *set);
void			julia(t_fractal *set);
void			celtic(t_fractal *set);
void			do_fractal(t_fractal *set);
void			update(t_fractal *set);
void			mandelbrot_set(t_fractal *set);

int				hook_keydown(int key, t_fractal *set);
/*>>BONUS<<*/
int				mouse_func(int button, int x, int y, t_fractal *set);
void			zoomin(t_fractal *set, int x, int y);
void			pthread(t_fractal *set);
void			juli_do_the_thing(t_fractal *set);

#endif
