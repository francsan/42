/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:40:11 by francsan          #+#    #+#             */
/*   Updated: 2022/01/15 19:45:35 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_print_numbers(void)
{
	char	b;
	char	c;

	b = '0';
	c = '9';
	while (b <= c)
	{
		ft_putchar(b);
		b = b + 1;
	}
}
