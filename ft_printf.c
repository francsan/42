/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:32:58 by francisco         #+#    #+#             */
/*   Updated: 2022/03/14 22:53:08 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_hex(int nbr, char c)
{
	int	len;
	int	num;

	len = 0;
	num = nbr;
	if (num < 0)
		num = (unsigned int)nbr;
	if (num < 10)
		len += ft_putchar(num + 48);
	else if (num < 16)
	{
		if (c == 'x')
			len += ft_putchar(num + 87);
		if (c == 'X')
			len += ft_putchar(num + 55);
	}
	else
	{
		len += ft_putnbr_hex(num / 16, c);
		len += ft_putnbr_hex(num % 16, c);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		len;
	
	va_start(a, s);
	len = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'x' || *s == 'X')
			{
				len += ft_putnbr_hex(va_arg(a, int), *s);
				s++;
			}
		}
		else
		{
			len += ft_putchar(*s);
			s++;
		}
	}
	va_end(a);
	return (len);
}

int	main()
{
	int	len;
	int	len2;
	int	nbr = -2147483648;

	len = ft_printf("Function: %x\n", nbr);
	len2 = printf("Original: %x\n", nbr);
	printf("Function: %i\nOriginal: %i\n", len, len2);
}