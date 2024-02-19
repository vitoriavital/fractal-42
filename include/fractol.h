/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:08:53 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/19 16:18:37 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fractol
{
	double		zoom_range;
	double		move_x;
	double		move_y;
	int			width;
	int			height;
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		type;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		c_real;
	double		c_img;
	int			red;
	int			blue;
	int			green;
	int			alpha;
	int			color_range;
	int			max_i;
}				t_fractol;

typedef struct s_set
{
	double		x0;
	double		y0;
	double		c_real;
	double		c_img;
	double		z_real;
	double		z_img;
}				t_set;

typedef struct s_colors
{
	int			red;
	int			blue;
	int			green;
	int			alpha;
}				t_colors;

int32_t			ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t			ft_def_color(int n, t_fractol fractol);
int				ft_mandelbrot_iterations(int x, int y, t_fractol fractol);
void			ft_hook(void *param);
void			my_scrollhook(double ydelta, double xdelta, void *param);
void			ft_build_fractal(void *param);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_zoom_in(t_fractol *fractol);
void			ft_zoom_out(t_fractol *fractol);
int				ft_julia_iterations(int x, int y, t_fractol fractol);
double			ft_atof(char *str);
int				ft_burning_iterations(int x, int y, t_fractol fractol);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_errors(char c);
void			ft_color_shift(t_fractol *fractol);

#endif
