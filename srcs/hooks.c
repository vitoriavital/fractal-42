/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:03:59 by mavitori          #+#    #+#             */
/*   Updated: 2024/01/31 11:21:11 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_hook(void *param)
{
	t_fractol	*fractol;
	mlx_t		*mlx;

	fractol = (t_fractol *)param;
	mlx = (*fractol).mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_zoom_in(t_fractol *fractol)
{
	double	zoom_before;

	zoom_before = (*fractol).zoom_range;
	(*fractol).zoom_range -= (0.1 * zoom_before);
	(*fractol).move_x *= 0.9;
	(*fractol).move_y *= 0.9;
}

void	ft_zoom_out(t_fractol *fractol)
{
	double	zoom_before;

	zoom_before = (*fractol).zoom_range;
	(*fractol).zoom_range += (0.1 * zoom_before);
	(*fractol).move_x *= 1.1;
	(*fractol).move_y *= 1.1;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (ydelta > 0)
		ft_zoom_in(fractol);
	else if (ydelta < 0)
		ft_zoom_out(fractol);
	if (xdelta < 0)
		ft_zoom_in(fractol);
	else if (xdelta > 0)
		ft_zoom_out(fractol);
}
