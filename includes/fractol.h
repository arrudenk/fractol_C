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

#ifndef FRACTOL_H
# define FRACTOL_H
# define W 800
# define H 800
# define THREADS 16

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

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

void			error(int error);

t_mlx			*init_mlx(void);
t_image			*new_image(t_mlx *mlx);
void			pixel_to_image(t_fractal *set);
void			clear_image(t_mlx *mlx);

void			select_fractal(const char *str, t_fractal *fractal);
t_fractal		*fractal_info(void);
void			do_fractal(t_fractal *set);
void			update(t_fractal *set);
void			pthread(t_fractal *set);

void			mandelbrot(t_fractal *set);
void			julia(t_fractal *set);
void			celtic(t_fractal *set);
void			tricorn(t_fractal *set);
void			perpen_mandelbrot(t_fractal *set);
void			perpen_celtic(t_fractal *set);
void			heart(t_fractal *set);
void			four_mandelbrot(t_fractal *set);

void			mandelbrot_set(t_fractal *set);
void			tricorn_set(t_fractal *set);
void			celtic_set(t_fractal *set);
void			juli_do_set(t_fractal *set);
void			perpen_mandelbrot_set(t_fractal *set);
void			perpen_celtic_set(t_fractal *set);
void			heart_set(t_fractal *set);
void			four_mandelbrot_set(t_fractal *set);

int				hook_keydown(int key, t_fractal *set);
int				mouse_func(int button, int x, int y, t_fractal *set);
int				exit_x(void);

#endif
