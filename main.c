/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:06:52 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 13:05:52 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			mandelbrot();
		else
			ft_printf("Invalid input: \n <Mandelbrot> \
			\n <Julia> <real value> <im value>");
	}
	else if (ac == 4)
	{
		if (ft_strcmp(av[1], "Julia") == 0)
			julia(av[2], av[3]);
		else
			ft_printf("Invalid input: \n <Mandelbrot> \
			\n <Julia> <real value> <im value>");
	}
	else
		ft_printf("Invalid input: \n <Mandelbrot> \
		\n <Julia> <real value> <im value>");
	return (0);
}
