/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:11:07 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/19 16:24:06 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	ft_def_bonus_color(int n, t_fractol *fractol, int color_range)
{
	int	color_value;

	if ((*fractol).type == 'M')
	{
		color_value = (int)(sin(0.1 * n) * 255);
		(*fractol).red = (color_range == 1) * color_value;
		(*fractol).green = (color_range == 0) * color_value;
		(*fractol).blue = (color_range == 2) * color_value;
	}
	else if ((*fractol).type == 'J')
	{
		color_value = (int)(255 * sin(0.02 * n));
		(*fractol).red = (color_range == 0) * color_value;
		(*fractol).green = (color_range == 1) * color_value;
		(*fractol).blue = (color_range == 2) * color_value;
	}
	else if ((*fractol).type == 'B')
	{
		color_value = (int)(255 * sin(0.02 * n));
		(*fractol).red = (color_range == 0) * color_value;
		(*fractol).green = (color_range == 1) * color_value;
		(*fractol).blue = (color_range == 2) * color_value;
	}
}

int32_t	ft_def_color(int n, t_fractol fractol)
{
	uint32_t	color;
	int			color_range;

	color_range = fractol.color_range % 3;
	if (n == 500)
		color = ft_pixel(0, 0, 0, 255);
	else
	{
		ft_def_bonus_color(n, &fractol, color_range);
		color = ft_pixel(fractol.red, fractol.green, fractol.blue, 255);
	}
	return (color);
}

void	ft_color_shift(t_fractol *fractol)
{
	fractol->color_range += 1;
	ft_build_fractal((void *)fractol);
}
