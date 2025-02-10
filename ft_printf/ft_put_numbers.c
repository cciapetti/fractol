/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:58:56 by cciapett          #+#    #+#             */
/*   Updated: 2025/01/02 16:34:49 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lennum(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	num;
	int	uni;

	num = 0;
	uni = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n >= 0 && n <= 9)
	{
		num = n + 48;
		write(1, &num, 1);
	}
	else if (n > 9)
	{
		uni = (n % 10) + 48;
		ft_putnbr(n / 10);
		write(1, &uni, 1);
	}
	else
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	return (ft_lennum(n));
}

int	ft_putunsint(unsigned int n)
{
	int	num;

	num = 0;
	if (n <= 9)
	{
		num = n + 48;
		write(1, &num, 1);
	}
	else if (n > 9)
	{
		ft_putunsint(n / 10);
		ft_putunsint(n % 10);
	}
	return (ft_lennum(n));
}

int	ft_putnumexa(unsigned long n, char c)
{
	int		len;
	char	*exa;

	len = 0;
	if (c == 'l')
		exa = "0123456789abcdef";
	else if (c == 'u')
		exa = "0123456789ABCDEF";
	if (n <= 15)
		len += write(1, &exa[n % 16], 1);
	else if (n >= 16)
	{
		len += ft_putnumexa(n / 16, c);
		len += ft_putnumexa(n % 16, c);
	}
	return (len);
}

int	ft_putpointeradd(void *p)
{
	int				len;
	unsigned long	p1;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p1 = (unsigned long)p;
	write(1, "0x", 2);
	len = ft_putnumexa(p1, 'l');
	return (len + 2);
}
