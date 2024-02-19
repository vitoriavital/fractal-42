/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:11:07 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/19 16:13:09 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	ft_def_color(int n, t_fractol fractol)
{
	uint32_t	color;
	int			color_value;
	int			color_range;

	color_range = fractol.color_range % 3;
	if (n == fractol.max_i)
		color = ft_pixel(0, 0, 0, 255);
	else
	{
		if (fractol.type == 'M')
		{
			fractol.red = (int)(sin(0.05 * n) * 255);
			fractol.green = (int)(sin(0.00 * n) * 255);
			fractol.blue = (int)(sin(0.00 * n) * 255);
		}
		else if (fractol.type == 'J')
		{
			color_value = (int)(255 * sin(0.02 * n));
			fractol.red = (color_range == 0) * color_value;
			fractol.green = (color_range == 1) * color_value;
			fractol.blue = (color_range == 2) * color_value;
		}
		color = ft_pixel(fractol.red, fractol.green, fractol.blue, 255);
	}
	return (color);
}

void	ft_color_shift(t_fractol *fractol)
{
	fractol->color_range += 1;
	ft_build_fractal((void *)fractol);
}
