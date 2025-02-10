/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:11:38 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 17:54:36 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_process_pixel(t_data *data, t_axis *borders, t_count *count)
{
	t_z		z;
	t_z		c;
	bool	isinside;

	c.im = borders->maxim - count->y * \
	((borders->maxim - borders->minim) / (HEIGHT - 1));
	c.re = borders->minre + count->x * \
	((borders->maxre - borders->minre) / (WIDTH - 1));
	z.re = c.re;
	z.im = c.im;
	count->i = ft_iteration(z, c);
	isinside = (count->i == MAXITER);
	if ((z.re >= borders->minre && z.re <= borders->maxre) || \
	(z.im >= borders->minim && z.im <= borders->maxim))
		ft_colorize(data->data_pixel, isinside, *count, data->flag);
}

void	ft_displayfract(t_data *data, t_axis *borders, int x, int y)
{
	t_count	count;

	count.y = 0;
	count.borders = borders;
	ft_axis(borders, x, y);
	while (count.y < HEIGHT)
	{
		count.x = 0;
		while (count.x < WIDTH)
		{
			ft_process_pixel(data, borders, &count);
			count.x++;
		}
		count.y++;
	}
}

int	mouse_hook_m(int button, int x, int y, t_win *program)
{
	if (button == 5)
	{
		program->data->borders->zoom += 0.5;
		program->data->data_pixel = (int *) \
		mlx_get_data_addr(program->data->img, &program->data->bpp, \
		&program->data->size_line, &program->data->endian);
		ft_displayfract(program->data, program->data->borders, x, y);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	else if (button == 4)
	{
		program->data->borders->zoom -= 0.5;
		program->data->data_pixel = (int *) \
		mlx_get_data_addr(program->data->img, &program->data->bpp, \
		&program->data->size_line, &program->data->endian);
		ft_displayfract(program->data, program->data->borders, x, y);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	return (0);
}

int	mandelbrot(void)
{
	t_win	program;
	t_data	im_data;
	t_axis	borders;

	im_data.borders = &borders;
	im_data.flag = 0;
	borders = ft_initialize_m(borders);
	program.mlx = mlx_init();
	program.win = mlx_new_window \
	(program.mlx, WIDTH, HEIGHT, "Mandelbrot fractol");
	program.data = &im_data;
	program.data->img = mlx_new_image(program.mlx, WIDTH, HEIGHT);
	if (!program.mlx || !program.win || !program.data->img)
		ft_clean(&program);
	im_data.data_pixel = (int *) \
	mlx_get_data_addr(program.data->img, &im_data.bpp, \
	&im_data.size_line, &im_data.endian);
	ft_displayfract(&im_data, &borders, WIDTH / 2, HEIGHT / 2);
	mlx_put_image_to_window(program.mlx, program.win, program.data->img, 0, 0);
	mlx_hook(program.win, KeyPress, KeyPressMask, key_hook_m, &program);
	mlx_hook(program.win, 17, 0, ft_clean, &program);
	mlx_mouse_hook(program.win, mouse_hook_m, &program);
	mlx_loop(program.mlx);
	ft_clean(&program);
	return (0);
}
