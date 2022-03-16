/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francisco <francisco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:26 by francsan          #+#    #+#             */
/*   Updated: 2022/03/16 16:53:27 by francisco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select(char c, va_list a)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(a, int));
	if (c == 's')
		len += ft_putstr(va_arg(a, char *));
	if (c == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putadd(va_arg(a, unsigned long));
	}
	if (c == 'd')
		len += ft_putnbr(va_arg(a, int));
	if (c == 'i')
		len += ft_putnbr(va_arg(a, int));
	if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(a, unsigned int));
	if (c == 'x' || c == 'X')
		len += ft_putnbr_hex(va_arg(a, int), c);
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	a;
	int		len;
	int		i;

	va_start(a, s);
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += ft_select(s[i + 1], a);
			if (s[i + 1] != '%')
				va_arg(a, void *);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(a);
	return (len);
}

/*#include <stdio.h>

int	main()
{
	int	i;
	int	j;

	i = printf("Original:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	j = ft_printf("Function:%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("Original: %i\nFunction: %i\n", i, j);
}*/