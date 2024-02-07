/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:07:27 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/01 12:47:23 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_initialize(int argc, char **argv, t_fractol *fractol)
{
	(*fractol).width = 720;
	(*fractol).height = 720;
	(*fractol).move_x = -2.0;
	(*fractol).move_y = -2.0;
	(*fractol).zoom_range = 4.0;
	(*fractol).color_range = 0.0;
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		(*fractol).type = 'M';
	else if (argc > 1 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		(*fractol).type = 'J';
		if (argc == 4)
		{
			(*fractol).c_real = ft_atof(argv[2]);
			(*fractol).c_img = ft_atof(argv[3]);
		}
		else
			return (ft_errors('J'));
	}
	else if (argc == 2 && ft_strncmp(argv[1], "burning", 7) == 0)
		(*fractol).type = 'B';
	else
		return (ft_errors('I'));
	return (0);
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_fractol	fractol;
	mlx_image_t	*image;
	int			valid;

	valid = ft_initialize(argc, argv, &fractol);
	if (valid == 1)
		return (1);
	mlx = mlx_init(fractol.width, fractol.height, "MLX42", true);
	if (!mlx)
		return (1);
	fractol.mlx = mlx;
	image = mlx_new_image(mlx, fractol.width, fractol.height);
	if (!image || mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		return (1);
	}
	fractol.image = image;
	mlx_loop_hook(mlx, ft_build_fractal, &fractol);
	mlx_loop_hook(mlx, ft_hook, &fractol);
	mlx_scroll_hook(mlx, &my_scrollhook, &fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
