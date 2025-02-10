/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:29:14 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 17:48:44 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_iteration(t_z z, t_z c)
{
	int		i;
	t_z		z_squared;
	double	temp;

	i = 0;
	while (i < MAXITER)
	{
		z_squared.re = z.re * z.re;
		z_squared.im = z.im * z.im;
		if (z_squared.re + z_squared.im > 4)
			break ;
		temp = z.re;
		z.re = z_squared.re - z_squared.im + c.re;
		z.im = 2 * temp * z.im + c.im;
		i++;
	}
	return (i);
}

void	ft_changecolor_m(t_win *program)
{
	if (program->data->flag == 0)
		program->data->flag = 1;
	else
		program->data->flag = 0;
	ft_displayfract(program->data, program->data->borders, \
	WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(program->mlx, program->win, \
	program->data->img, 0, 0);
}

void	ft_changecolor_j(t_win *program)
{
	if (program->data->flag == 0)
		program->data->flag = 1;
	else
		program->data->flag = 0;
	ft_displayjulia(program, WIDTH / 2, HEIGHT / 2, program->c);
	mlx_put_image_to_window(program->mlx, program->win, \
	program->data->img, 0, 0);
}
