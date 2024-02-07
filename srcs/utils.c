/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:47:52 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/01 14:12:13 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	while ((i < n) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		result = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (result != 0)
			return (result);
		i++;
	}
	return (result);
}

double	ft_atof(char *str)
{
	double	res;
	int		sign;
	int		decimal_count;

	res = 0;
	sign = 1;
	decimal_count = 1;
	if (str == NULL)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		decimal_count = decimal_count * 10;
	}
	return (res / decimal_count * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

int	ft_errors(char c)
{
	if (c == 'I')
	{
		ft_putstr_fd("Invalid option.\n", 1);
		ft_putstr_fd("You must choose either mandelbrot or julia.\n", 1);
	}
	else if (c == 'J')
	{
		ft_putstr_fd("For julia, you need to include 2 arguments.\n", 1);
		ft_putstr_fd("Ex: ./fractol julia <real_value> <imaginary_value>\n", 1);
	}
	return (1);
}
