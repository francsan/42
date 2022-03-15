/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:26:26 by francsan          #+#    #+#             */
/*   Updated: 2022/03/15 19:13:33 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_select(char *s, va_list a)
{
	int	len;

	len = 0;
	s++;
	if (*s == 'c')
		len += ft_putchar(va_arg(a, int));
	if (*s == 's')
		len += ft_putstr(va_arg(a, char *));
	if (*s == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putadd(va_arg(a, unsigned long));
	}
	if (*s == 'd')
		len += ft_putnbr(va_arg(a, int));
	if (*s == 'i')
		len += ft_putnbr(va_arg(a, int));
	if (*s == 'u')
		len += ft_putnbr_unsigned(va_arg(a, unsigned int));
	if (*s == 'x' || *s == 'X')
		len += ft_putnbr_hex(va_arg(a, int), *s);
	if (*s == '%')
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
			len += ft_select((char *)&s[i], a);
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
	int	k = 0;
	int	*l;

	l = &k;
	i = printf("%p\n", l);
	j = ft_printf("%p\n", l);
	printf("%d\n%d\n", i, j);
}*/
