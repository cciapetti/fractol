/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:41:07 by cciapett          #+#    #+#             */
/*   Updated: 2025/01/02 16:27:16 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_lennum(long n);
int	ft_putnbr(int n);
int	ft_putunsint(unsigned int n);
int	ft_putnumexa(unsigned long n, char c);
int	ft_putpointeradd(void *p);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif