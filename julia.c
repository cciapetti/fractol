/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:12:02 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 17:56:47 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_process_julia_pixel(t_win *program, t_z c, t_count *count)
{
	t_z		z;
	bool	isinside;

	z.im = program->data->borders->maxim - count->y * ((program->data-> \
	borders->maxim - program->data->borders->minim) / (HEIGHT - 1));
	z.re = program->data->borders->minre + count->x * ((program->data-> \
	borders->maxre - program->data->borders->minre) / (WIDTH - 1));
	count->i = ft_iteration(z, c);
	isinside = (count->i == MAXITER);
	if ((z.re >= program->data->borders->minre && \
	z.re <= program->data->borders->maxre) || \
	(z.im >= program->data->borders->minim && \
	z.im <= program->data->borders->maxim))
		ft_colorize(program->data->data_pixel, isinside, \
		*count, program->data->flag);
}

void	ft_displayjulia(t_win *program, int x, int y, t_z c)
{
	t_count	count;

	count.y = 0;
	count.borders = program->data->borders;
	ft_axis(program->data->borders, x, y);
	while (count.y < HEIGHT)
	{
		count.x = 0;
		while (count.x < WIDTH)
		{
			ft_process_julia_pixel(program, c, &count);
			count.x++;
		}
		count.y++;
	}
}

int	mouse_hook_j(int button, int x, int y, t_win *program)
{
	if (button == 5)
	{
		program->data->borders->zoom += 0.25;
		program->data->data_pixel = (int *) \
		mlx_get_data_addr(program->data->img, &program->data->bpp, \
		&program->data->size_line, &program->data->endian);
		ft_displayjulia(program, x, y, program->c);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	else if (button == 4)
	{
		program->data->borders->zoom -= 0.25;
		program->data->data_pixel = (int *) \
		mlx_get_data_addr(program->data->img, &program->data->bpp, \
		&program->data->size_line, &program->data->endian);
		ft_displayjulia(program, x, y, program->c);
		mlx_put_image_to_window(program->mlx, program->win, \
		program->data->img, 0, 0);
	}
	return (0);
}

int	julia(char *c_re, char *c_im)
{
	t_win	program;
	t_data	im_data;
	t_axis	borders;

	im_data.flag = 0;
	program.c.re = ft_converter(c_re);
	program.c.im = ft_converter(c_im);
	im_data.borders = &borders;
	borders = ft_initialize_j(borders);
	program.mlx = mlx_init();
	program.win = mlx_new_window(program.mlx, WIDTH, HEIGHT, "Julia fractol");
	program.data = &im_data;
	program.data->img = mlx_new_image(program.mlx, WIDTH, HEIGHT);
	if (!program.mlx || !program.win || !program.data->img)
		ft_clean(&program);
	im_data.data_pixel = (int *)mlx_get_data_addr \
	(program.data->img, &im_data.bpp, &im_data.size_line, &im_data.endian);
	ft_displayjulia(&program, WIDTH / 2, HEIGHT / 2, program.c);
	mlx_put_image_to_window(program.mlx, program.win, program.data->img, 0, 0);
	mlx_hook(program.win, KeyPress, KeyPressMask, key_hook_j, &program);
	mlx_hook(program.win, 17, 0, ft_clean, &program);
	mlx_mouse_hook(program.win, mouse_hook_j, &program);
	mlx_loop(program.mlx);
	ft_clean(&program);
	return (0);
}
