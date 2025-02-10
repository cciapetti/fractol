/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:02:14 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 18:04:18 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_clean(void *arg)
{
	t_win	*program;

	program = (t_win *)arg;
	mlx_destroy_image(program->mlx, program->data->img);
	mlx_destroy_window(program->mlx, program->win);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
	exit(0);
	return (0);
}

t_axis	*ft_translate(int key, t_win *program, double range_re, double range_im)
{
	if (key == XK_Right)
	{
		program->data->borders->minre += 0.1 * range_re;
		program->data->borders->maxre += 0.1 * range_re;
	}
	else if (key == XK_Left)
	{
		program->data->borders->minre -= 0.1 * range_re;
		program->data->borders->maxre -= 0.1 * range_re;
	}
	else if (key == XK_Up)
	{
		program->data->borders->minim += 0.1 * range_im;
		program->data->borders->maxim += 0.1 * range_im;
	}
	else if (key == XK_Down)
	{
		program->data->borders->minim -= 0.1 * range_im;
		program->data->borders->maxim -= 0.1 * range_im;
	}
	return (program->data->borders);
}

int	key_hook_m(int key, void *arg)
{
	t_win	*program;
	double	range_re;
	double	range_im;

	program = (t_win *)arg;
	range_re = (program->data->borders->maxre - program->data->borders->minre);
	range_im = (program->data->borders->maxim - program->data->borders->minim);
	if (key == XK_Escape)
		ft_clean(program);
	program->data->borders = ft_translate(key, program, range_re, range_im);
	if (key == XK_Up || key == XK_Left || key == XK_Down || key == XK_Right)
	{
		ft_displayfract(program->data, program->data->borders, \
		WIDTH / 2, HEIGHT / 2);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	if (key == 65293)
		ft_changecolor_m(program);
	return (0);
}

int	key_hook_j(int key, void *arg)
{
	t_win	*program;
	double	range_re;
	double	range_im;

	program = (t_win *)arg;
	range_re = (program->data->borders->maxre - program->data->borders->minre);
	range_im = (program->data->borders->maxim - program->data->borders->minim);
	if (key == XK_Escape)
		ft_clean(program);
	program->data->borders = ft_translate(key, program, range_re, range_im);
	if (key == XK_Up || key == XK_Left || key == XK_Down || key == XK_Right)
	{
		ft_displayjulia(program, WIDTH / 2, HEIGHT / 2, \
		program->c);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	if (key == 65293)
		ft_changecolor_j(program);
	return (0);
}

void	ft_axis(t_axis *borders, int x, int y)
{
	double	range_re;
	double	range_im;
	double	mouse_re;
	double	mouse_im;

	range_re = (borders->maxre - borders->minre);
	range_im = (borders->maxim - borders->minim);
	mouse_re = borders->minre + (x / (double)WIDTH) * range_re;
	mouse_im = borders->maxim - (y / (double)HEIGHT) * range_im;
	borders->minre = mouse_re + (borders->minre - mouse_re) * borders->zoom;
	borders->maxre = mouse_re + (borders->maxre - mouse_re) * borders->zoom;
	borders->minim = mouse_im + (borders->minim - mouse_im) * borders->zoom;
	borders->maxim = mouse_im + (borders->maxim - mouse_im) * borders->zoom;
	borders->zoom = 1;
}
