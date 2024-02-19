/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:10:46 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/19 16:12:27 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_mandelbrot_iterations(int x, int y, t_fractol fractol)
{
	int		i;
	double	real_temp;
	t_set	s;

	s.x0 = (double)x;
	s.y0 = (double)y;
	s.c_real = (s.x0 / fractol.width) * fractol.zoom_range + fractol.move_x;
	s.c_img = (s.y0 / fractol.height) * fractol.zoom_range + fractol.move_y;
	s.z_real = 0.0;
	s.z_img = 0.0;
	i = 0;
	while (s.z_real * s.z_real + s.z_img * s.z_img <= (2 * 2)
		&& i < fractol.max_i)
	{
		real_temp = s.z_real * s.z_real - s.z_img * s.z_img + s.c_real;
		s.z_img = 2.0 * s.z_real * s.z_img + s.c_img;
		s.z_real = real_temp;
		i++;
	}
	return (i);
}
