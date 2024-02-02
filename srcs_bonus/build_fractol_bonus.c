/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_fractol_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:37:17 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/02 17:31:39 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_build_fractal(void *param)
{
	int			n;
	uint32_t	color;
	t_fractol	*fractol;
	uint32_t	x;
	uint32_t	y;

	fractol = (t_fractol *)param;
	x = 0;
	fractol->max_i = 500;
	while (x < fractol->image->width)
	{
		y = 0;
		while (y < fractol->image->height)
		{
			if (fractol->type == 'M')
				n = ft_mandelbrot_iterations(x, y, *fractol);
			else if (fractol->type == 'J')
				n = ft_julia_iterations(x, y, *fractol);
			else if (fractol->type == 'B')
				n = ft_burning_iterations(x, y, *fractol);
			color = ft_def_color(n, *fractol);
			mlx_put_pixel(fractol->image, x, y, color);
			y++;
		}
		x++;
	}
}
