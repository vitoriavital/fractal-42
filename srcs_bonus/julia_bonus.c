/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:20:34 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/19 16:13:52 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_julia_iterations(int x, int y, t_fractol fractol)
{
	int		i;
	double	real_temp;
	t_set	s;

	s.x0 = (double)x;
	s.y0 = (double)y;
	s.z_real = (s.x0 / fractol.width) * fractol.zoom_range + fractol.move_x;
	s.z_img = (s.y0 / fractol.height) * fractol.zoom_range + fractol.move_y;
	s.c_img = fractol.c_img;
	s.c_real = fractol.c_real;
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
