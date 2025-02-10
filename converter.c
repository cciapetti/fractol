/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:13:53 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 13:34:06 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static long	ft_atol(char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	result = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign++;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	if (sign == 1)
		return (result * (-1));
	else
		return (result);
}

static int	ft_index(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '.')
			break ;
		i++;
	}
	return (pow(10, ft_strlen(s1) -1 - i));
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_check(char *s1)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == '.')
		{
			toggle = 1;
			return (toggle);
		}
		i++;
	}
	return (toggle);
}

double	ft_converter(char *s1)
{
	int		i;
	char	**matrix;
	char	*s2;
	double	num;

	i = ft_index(s1);
	if (ft_check(s1) == 1)
	{
		matrix = ft_split(s1, '.');
		s2 = ft_strjoin(matrix[0], matrix[1]);
		free_matrix(matrix);
		num = ft_atol(s2);
		free(s2);
		return (num / i);
	}
	else
		num = ft_atol(s1);
	return (num);
}
