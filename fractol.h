/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:34:38 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 17:53:44 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#define WIDTH 400
#define HEIGHT 300
#define MAXITER	100

typedef struct s_axis
{
	double	zoom;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
}	t_axis;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		*data_pixel;
	int		flag;
	t_axis	*borders;
}				t_data;

typedef struct s_z
{
	double	re;
	double	im;
}	t_z;

typedef struct s_count
{
	int		x;
	int		y;
	int		i;
	t_axis	*borders;
}	t_count;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_data	*data;
	t_z		c;
	t_count	count;
}	t_win;

int		ft_strcmp(char *s1, char *s2);
int		create_trgb(int t, int r, int g, int b);
int		ft_clean(void *arg);
int		key_hook_m(int key, void *arg);
int		key_hook_j(int key, void *arg);
int		mouse_hook_j(int button, int x, int y, t_win *program);
int		mouse_hook_m(int button, int x, int y, t_win *program);
int		ft_iteration(t_z z, t_z c);
int		mandelbrot(void);
int		julia(char *c_re, char *c_im);
void	ft_displayjulia(t_win *program, int x, int y, t_z c);
void	ft_colorize(int *data, bool isInside, t_count count, int flag);
void	ft_axis(t_axis *borders, int x, int y);
void	ft_displayfract(t_data	*data, t_axis *borders, int x, int y);
void	ft_changecolor_m(t_win *program);
void	ft_changecolor_j(t_win *program);
double	ft_converter(char *s1);
t_axis	ft_initialize_m(t_axis borders);
t_axis	ft_initialize_j(t_axis borders);
t_axis	*ft_translate(int key, t_win *program, double range_re, double range_im);