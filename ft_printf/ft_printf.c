/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:40:44 by cciapett          #+#    #+#             */
/*   Updated: 2025/02/10 12:07:42 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

static int	ft_isinconv(char *conv, char c)
{
	int		i;

	i = 0;
	while (conv[i] != '\0')
	{
		if (conv[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_choice_conv(char c, va_list argp)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(argp, int));
	else if (c == 's')
		len = ft_putstr(va_arg(argp, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(argp, int));
	else if (c == '%')
		len = write(1, "%", 1);
	else if (c == 'u')
		len = ft_putunsint(va_arg(argp, unsigned int));
	else if (c == 'x')
		len = ft_putnumexa(va_arg(argp, unsigned int), 'l');
	else if (c == 'X')
		len = ft_putnumexa(va_arg(argp, unsigned int), 'u');
	else if (c == 'p')
		len = ft_putpointeradd(va_arg(argp, void *));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	argp;
	char	*conv;
	int		i;
	int		j;

	i = -1;
	j = 0;
	conv = "cspdiuxX%";
	if (s == NULL)
		return (-1);
	va_start(argp, s);
	while (s[++i] != '\0')
	{
		if (s[i] != '%')
			j += write (1, &s[i], 1);
		else if (s[i] == '%' && ft_isinconv(conv, s[i + 1]) == 0)
			j += write (1, &s[i], 1);
		else if (s[i] == '%' && ft_isinconv(conv, s[i + 1]) == 1)
		{
			j += ft_choice_conv(s[i + 1], argp);
			i++;
		}
	}
	va_end(argp);
	return (j);
}
