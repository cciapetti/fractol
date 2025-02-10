/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:00:35 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 17:58:52 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_colorize(int *data, bool isInside, t_count count, int flag)
{
	if (isInside == false && flag == 0)
		data[(int)(count.y * WIDTH + count.x)] = create_trgb(255, \
		255 / MAXITER * count.i + count.i, count.i * 10, count.i * 15);
	else if (isInside == false && flag == 1)
		data[(int)(count.y * WIDTH + count.x)] = create_trgb(255, \
		count.i * 50, count.i * 40, count.i * 30);
	else
		data[(int)(count.y * WIDTH + count.x)] = create_trgb(0, 0, 0, 0);
}

t_axis	ft_initialize_m(t_axis borders)
{
	borders.zoom = 1;
	borders.maxre = 1.0;
	borders.minre = -2.0;
	borders.minim = -1.2;
	borders.maxim = borders.minim + (borders.maxre - borders.minre) \
	* HEIGHT / WIDTH;
	return (borders);
}

t_axis	ft_initialize_j(t_axis borders)
{
	borders.zoom = 1;
	borders.maxre = 2.0;
	borders.minre = -2.0;
	borders.minim = -1.5;
	borders.maxim = borders.minim + (borders.maxre - borders.minre) \
	* HEIGHT / WIDTH;
	return (borders);
}
