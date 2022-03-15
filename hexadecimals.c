/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:44:06 by francsan          #+#    #+#             */
/*   Updated: 2022/03/15 16:29:49 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char c)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	else if (nbr < 16)
	{
		if (c == 'x')
			len += ft_putchar(nbr + 87);
		if (c == 'X')
			len += ft_putchar(nbr + 55);
	}
	else
	{
		len += ft_putnbr_hex(nbr / 16, c);
		len += ft_putnbr_hex(nbr % 16, c);
	}
	return (len);
}

int	ft_putadd(void *p)
{
	int				len;
	unsigned long	nbr;

	len = 0;
	nbr = (unsigned long)&p;
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	else if (nbr < 16)
		len += ft_putchar(nbr + 87);
	else
	{
		len += ft_putadd(nbr / 16);
		len += ft_putadd(nbr % 16);
	}
	return (len);
}
